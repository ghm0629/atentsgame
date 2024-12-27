#include "MinoJ.h"

void MinoJ::OnInitialize()
{
	width = 3;
	height = 3;

	const int size = 9;
	CellType mino[SpinCount][size] = {
		{
			CellType::Blank, CellType::Block, CellType::Blank,
			CellType::Blank, CellType::Block, CellType::Blank,
			CellType::Block, CellType::Block, CellType::Blank
		},
		{
			CellType::Block, CellType::Blank, CellType::Blank,
			CellType::Block, CellType::Block, CellType::Block,
			CellType::Blank, CellType::Blank, CellType::Blank
		},
		{
			CellType::Blank, CellType::Block, CellType::Block,
			CellType::Blank, CellType::Block, CellType::Blank,
			CellType::Blank, CellType::Block, CellType::Blank
		},
		{
			CellType::Blank, CellType::Blank, CellType::Blank,
			CellType::Block, CellType::Block, CellType::Block,
			CellType::Blank, CellType::Blank, CellType::Block
		}
	};

	data = new CellType*[SpinCount];
	for (int i = 0; i < SpinCount; i++)
	{
		data[i] = new CellType[size];
		memcpy(data[i], mino[i], sizeof(CellType) * size);	// 임시 데이터를 data에 복사
	}
}

// 테트로미노의 종류
// I
// J
// L
// O
// S
// T
// Z