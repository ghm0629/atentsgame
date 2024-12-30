#pragma once
#include "Tetromino.h"
class DropBlock
{
public:
	void Initialize();
	void Update(float deltaTime);
	void Destroy();

private:
	enum class MinoType : char
	{
		I = 0,
		J,
		L,
		O,
		S,
		T,
		Z,
		NUM_OF_TYPES
	};

	Tetromino* tetrominos[static_cast<int>(MinoType::NUM_OF_TYPES)];
};

