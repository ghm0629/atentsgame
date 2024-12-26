#pragma once
#include <functional>

//테트리스에서 사용되는 키 종류(크기는 char 8비트 최대 256가지 표현)
enum class KeyType : char
{
	Left = 0,		// 왼쪽 이동용 키
	Right,			// 오른쪽 이동용 키
	Spin,			// 회전용 키
	SoftDrop,		// 빠르게 떨어지게 하는 키
	HardDrop,		// 바닥으로 즉시 떨어지게 하는 키
	Esc,			// Esc키
	NUM_OF_KEYTYPE	// 키 종류가 몇 개인지 
};

using Action = std::function<void()>;