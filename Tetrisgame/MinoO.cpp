#include "MinoO.h"

void MinoO::OnInitialize() {
    width = 2;
    height = 2;

    const int size = 4;
    CellType mino[SpinCount][size] = {
        {
            CellType::Block, CellType::Block,
            CellType::Block, CellType::Block
        },
        {
            CellType::Block, CellType::Block,
            CellType::Block, CellType::Block},
        {
            CellType::Block, CellType::Block,
            CellType::Block, CellType::Block
        },
        {
            CellType::Block, CellType::Block,
            CellType::Block, CellType::Block
        }
    };

    data = new CellType * [SpinCount];
    for (int i = 0; i < SpinCount; i++) {
        data[i] = new CellType[size];
        memcpy(data[i], mino[i], sizeof(CellType) * size);
    }
}