#include "Stage.h"

void Stage::Initialize()
{
	renderText = new char[canvasTextArraySize];
	memset(renderText, 0, canvasTextArraySize);	// canvasText를 0으로 채우기, char 크기는 1
}

void Stage::Destroy()
{
	delete renderText;
	renderText = nullptr;
}

void Stage::Update(float deltaTime)
{
	DataToText();	// 마지막 줄에 있어야 함
}

void Stage::DataToText()
{
	// 배경 데이터 넣기
	// StageBackground에 있는 데이터를 canvas로 (sizeof(CellType) * FullWidth * FullHeight)만큼 복사
	memcpy(canvas, StageBackGround, sizeof(CellType) * FullWidth * FullHeight);


	// 라인 데이터 넣기
	
	// 블록 데이터 넣기

	// 텍스트로 변경하기
	memset(renderText, 0, canvasTextArraySize);	// 일단 깨끗하게 정리
	for (int y = 0; y < FullHeight; y++)
	{
		for (int x = 0; x < FullWidth; x++)
		{
			int index = static_cast<int>(canvas[y][x]);
			strcat_s(renderText, canvasTextArraySize, enumToChar[index]);
		}
		strcat_s(renderText, canvasTextArraySize, "\n");
	}

}


