#include "Stage.h"
#include "Random.h"
#include "Logger.h"
#include "GameManager.h"

void Stage::Initialize()
{
	// 라인데이터 초기화
	memset(lineData, static_cast<char>(CellType::Blank), sizeof(CellType) * StageWidth * LinesHeight);

	// 출력 텍스트 초기화
	renderText = new char[canvasTextArraySize];
	memset(renderText, 0, canvasTextArraySize);	// canvasText를 0으로 채우기, char 크기는 1

	// 드랍블럭 초기화
	pDropBlock = new DropBlock();
	pDropBlock->Initialize();
		
	pDropBlock->onMoveDown = std::bind(&Stage::MoveDownProcess, this, std::placeholders::_1);
	pDropBlock->onMoveSide = std::bind(&Stage::CheckValidPosition, this, std::placeholders::_1, nullptr);
	pDropBlock->onSpin = std::bind(&Stage::WallKickProcess, this, std::placeholders::_1);
	pDropBlock->onHardDrop = std::bind(&Stage::HardDropProcess, this, std::placeholders::_1);
}

void Stage::Destroy()
{
	// 드랍블럭 제거
	pDropBlock->Destroy();
	delete pDropBlock;
	pDropBlock = nullptr;

	// 출력 텍스트 제거
	delete renderText;
	renderText = nullptr;
}

void Stage::Update(float deltaTime)
{
	penaltyElapsedTime += deltaTime;	// 패널티 시간 증가
	if (penaltyElapsedTime > penaltyInterval)	// 패널티 시간이 지나면
	{
		GeneratePenaltyBlocks();			// 주기적으로 패널티 블록 생성
		penaltyElapsedTime = 0.0f;		// 시간 초기화
	}
	pDropBlock->Update(deltaTime);		// 드랍블럭 업데이트

	DataToText();	// 마지막 줄에 있어야 함
}

void Stage::DataToText()
{
	// 기본 구조 : canvas에 CellType을 배치하기 - canvas의 정보를 바탕으로 text로 변경하기

	// 배경 데이터 넣기
	// StageBackground에 있는 데이터를 canvas로 (sizeof(CellType) * FullWidth * FullHeight)만큼 복사
	memcpy(canvas, StageBackground, sizeof(CellType) * FullWidth * FullHeight);

	// 라인 데이터 넣기
	for (int y = 0; y < LinesHeight; y++)
	{
		for (int x = 0; x < StageWidth; x++)
		{
			if (lineData[y][x] == CellType::Line)	// line만 기록(멀쩡한 부분이 덮어써지는 것 방지)
			{
				canvas[Origin.y + y][Origin.x + x] = CellType::Line;
			}
		}
	}

	// 블록 데이터 넣기
	const Position* pPositions = pDropBlock->GetCurrent()->GetMinos();	// 블럭의 위치 정보
	const Position position = Origin + pDropBlock->GetCurrentPosition(); // 원점에 드랍블럭의 위치 더하기
	for (int i = 0; i < Tetromino::TetroCount; i++)
	{
		int x = position.x + pPositions[i].x;
		int y = position.y + pPositions[i].y;
		canvas[y][x] = CellType::Block;		
	}

	// 텍스트로 변경하기
	memset(renderText, 0, canvasTextArraySize);	// 일단 깨끗하게 정리
	for (int y = 0; y < FullHeight; y++)
	{
		for (int x = 0; x < FullWidth; x++)
		{
			int index = static_cast<int>(canvas[y][x]);	// enum을 int로 변환
			strcat_s(renderText, canvasTextArraySize, enumToChar[index]);	// enumToChar[index]를 renderText에 붙이기
		}
		strcat_s(renderText, canvasTextArraySize, "\n");	// 한 줄이 끝나면 개행
	}
}

bool Stage::CheckValidPosition(const DropBlock& block, const Position* pTargetPosition)
{	
	const Position* pMinoPositions = block.GetCurrent()->GetMinos();	// 각각의 위치
	
	if (pTargetPosition == nullptr)	// 타겟 위치가 없다면
		pTargetPosition = &block.GetCurrentPosition();		// 현재 위치
	
	bool isSuccess = true;

	int size = static_cast<int>(Tetromino::TetroCount);
	for(int i = 0; i < size; i++)
	{
		Position minoPos = *pTargetPosition + *(pMinoPositions + i);	// 현재 위치 + 각각의 위치(i번째)
		if (!(minoPos.x >= 0 && minoPos.x < StageWidth)			// 위치 중 하나가 좌우의 경계랑 겹치거나 나갔다.
			|| !(minoPos.y >= 0 && minoPos.y < LinesHeight)		// 위치 중 하나가 위아래의 경계랑 겹치거나 나갔다.
			|| lineData[minoPos.y][minoPos.x] != CellType::Blank)	// 빈 칸이 아닌 경우
		{
			isSuccess = false;
			break;
		}
	}

	return isSuccess;
}

bool Stage::MoveDownProcess(const DropBlock& block)
{
	Position position = block.GetCurrentPosition();
	bool isMovable = CheckMovablePosition(position, block.GetCurrent()->GetMinos());
	if (!isMovable)
	{
		position.y--;	// 한 칸 위쪽으로 처리
		AddLine(position, block);	// 라인에 추가

		// 게임 오버가 되었는지 안 되었는지 체크
		if (CheckGameOver())
		{
			Logger::Print("Game Over!\n");
			GameManager::Get().ExcuteGameOver();
		}
	}
	return isMovable;
}

void Stage::HardDropProcess(const DropBlock& block)
{
	// block을 바닥까지 내리기
	//		바닥 찾기(stage의 바닥과 line에 처음 닿는 부분)
	Position groundPosition = FindGroundPosition(block.GetCurrentPosition(), block.GetCurrent()->GetMinos());


	// 바닥에 닿은 block을 라인에 추가하기
	//		한 줄이 가득 찼는지 확인
	//			해당 줄 삭제
	//			삭제된 줄 윗줄을 모두 아래로 내리기
	AddLine(groundPosition, block);

	// block 리셋(임시로 const 제거)
	const_cast<DropBlock&>(block).Reset();

	// 게임 오버가 되었는지 안되었는지 체크
	if ( CheckGameOver() )
	{
		Logger::Print("Game Over!\n");
		GameManager::Get().ExcuteGameOver();
	}
}

bool Stage::WallKickProcess(const DropBlock& block)
{
	bool isSuccess = CheckValidPosition(block);
	if (!isSuccess)
	{
		const Position kickTable[5] = { {1,0}, {-1,0}, {0,-1}, {2,0}, {-2,0} };	// 5개의 방향 확인
		int kickCount = 5;
		Position basePosition = block.GetCurrentPosition();

		for (int i = 0; i < kickCount; i++)
		{
			Position target = basePosition + kickTable[i];	// 기본 위치에서 킥테이블에 지정된 만큼 이동한 위치를 체크
			isSuccess = CheckValidPosition(block, &target);	// 이동 가능한지 확인
			if (isSuccess)	// 이동 가능하면
			{
				const_cast<DropBlock&>(block).SetCurrentPosition(target);	// 새 위치로 이동이 가능하면 위치 재설정하고 종료
				break;
			}
		}
	}
	return isSuccess;
}

Position Stage::FindGroundPosition(const Position& blockPosition, const Position* pMinoPositions)
{
	Position check = { blockPosition.x, 0 };	// 체크할 위치
	int startY = max(0, blockPosition.y);	// 블럭 크기가 3*3인 경우는 1이고 2*2인 경우는 2다. max는 둘 중 큰 것 고르는 함수
	int endY = static_cast<int>(LinesHeight);	// Y의 최대 크기
	bool isSuccess = true;						// 처음으로 실패(블럭이 이동 불가능)한 Y위치를 찾기 위한 bool

	for (int y = startY; isSuccess && (y < endY); y++)	// 종료조건은 처음으로 실패하거나 y가 스테이지의 끝까지 갔을 때. && 빠르게 연산 끝나는 것을 앞쪽에 배치
	{
		check.y = y;	// y를 check에 넣기
		isSuccess = CheckMovablePosition(check, pMinoPositions);		// 이동 가능한지 확인
	}
	
	if (!isSuccess)	// 실패했다면
	{
		check.y--;	// 중간에 못 가는 지역이 있어서 for문이 끝났다면 check의 y를 1 감소(마지막으로 성공한 위치)
	}

	return check;	// 마지막으로 성공한 위치 반환
}

bool Stage::CheckMovablePosition(const Position& basePosition, const Position* pMinoPositions)
{
	bool isSuccess = true;
	int size = Tetromino::TetroCount;
	for (int i = 0; i < size; i++)
	{
		Position minoPosition = basePosition + *(pMinoPositions + i);	// 블럭의 위치를 하나씩 더한다.
		{
			if (minoPosition.y >= static_cast<int>(LinesHeight)					// 밖을 벗어났거나 Blank가 아니면
				|| lineData[minoPosition.y][minoPosition.x] != CellType::Blank)	// 이동 불가능한 위치
			{
				isSuccess = false;		// 못가는 위치다.
				break;
			}
		}
	}

	return isSuccess;
}

void Stage::AddLine(Position& basePosition, const DropBlock& block)
{
	int minY = FullHeight;
	int maxY = -1;

	const Position* pMinoPositions = block.GetCurrent()->GetMinos();	// 블럭의 위치 정보
	int size = static_cast<int>(Tetromino::TetroCount);
	for (int i = 0; i < size; i++)
	{
		Position minoPos = basePosition + *(pMinoPositions + i);	// pMinoPositions에 있는 항목들을 하나씩 basePosition에 더한다.
	  //Position minoPos = basePosition + pMinoPositions[i]; 와 같음
		lineData[minoPos.y][minoPos.x] = CellType::Line;	// 라인에 블럭 추가

		minY = min(minY, minoPos.y);	// 최소값 찾기
		maxY = max(maxY, minoPos.y);	// 최대값 찾기
	}

	ClearFullLines(maxY, minY - 1);	// 가득찬 줄 제거 처리
}

void Stage::ClearFullLines(int start, int end)
{
	std::vector<int> fullLines;	// 가득찬 줄의 번호들을 기록하는 벡터
	fullLines.reserve(4);		// 한번에 제거 가능한 줄은 최대 4줄이니까

	const CellType fullLineData[StageWidth] = {
		CellType::Line, CellType::Line, CellType::Line, CellType::Line, CellType::Line,
		CellType::Line, CellType::Line, CellType::Line, CellType::Line, CellType::Line
	};

	for (int y = start; y > end; y--)		// 시작이 아래쪽
	{
		if (memcmp(fullLineData, lineData[y], sizeof(fullLineData)) == 0)	// 가득찬 줄인지 확인
		{
			fullLines.push_back(y);	// 가득찬 줄이면 줄번호를 기록
		}
	}

	/*순행 순서대로 채울 때
	for (auto a : Iterator)
	{}*/
	// 가득 찬 줄을 위에서부터 제거
	for (auto rIter = fullLines.rbegin(); rIter != fullLines.rend(); rIter++)	// 역순으로 제거
	{
		// 첫줄부터 가득찬 줄 앞까지 통채로 한 줄 내리기
		memmove(&lineData[1][0], &lineData[0][0], sizeof(CellType) * StageWidth * (*rIter));	// 명시적으로 위치 지정하여 안정성이 높다
	  //memcpy(&lineData[1][0], &lineData[0][0], sizeof(CellType) * StageWidth * (*rIter));		// 지금은 컴파일러가 발달하여 덮어쓰기 전에 복사되어 사용해도 상관없음
	}
}

void Stage::GeneratePenaltyBlocks()
{
	// 모든 라인을 위로 한 칸 옮기기
	memmove(&lineData[0][0], &lineData[1][0], sizeof(CellType) * StageWidth * (LinesHeight - 1));
	
	// 마지막줄에 블럭들을 랜덤하게 생성하기(각 칸 별로 90% 확률로 생성)
	for (int i = 0; i < StageWidth; i++)
	{
		if (Random::Get().GetRandomFloat() < 0.9f)
		{
			// 90% 확률
			lineData[LinesHeight - 1][i] = CellType::Line;
		}
		else
		{
			// 10% 확률
			lineData[LinesHeight - 1][i] = CellType::Blank;
		}
	}
	int index = Random::Get().GetRandom(10);	// 0~9까지의 랜덤한 숫자
	lineData[LinesHeight - 1][index] = CellType::Blank;	// 하나는 확정

	// 게임 오버 체크
	if (CheckGameOver())
	{
		Logger::Print("Game Over!\n");
		GameManager::Get().ExcuteGameOver();
	}
}

bool Stage::CheckGameOver()
{	
		const CellType emptyLineData[StageWidth] = {
		CellType::Blank, CellType::Blank, CellType::Blank, CellType::Blank, CellType::Blank,
		CellType::Blank, CellType::Blank, CellType::Blank, CellType::Blank, CellType::Blank
		};
		bool isGameOver = false;
		for (int y = 0; y < SpawnHeight; y++)	// 처음 테트로미노가 생성되는 곳의 높이까지
		{
			if (memcmp(emptyLineData, lineData[y], sizeof(emptyLineData)) != 0)	// 빈 줄이 아닌 경우
			{
				isGameOver = true;
				break;
			}
		}	
	return isGameOver;

}
