#pragma once
#include <ctime>
#include "Singleton.h"
#include "System.h"
#include "ConsoleDoubleBuffer.h"
#include "Input.h"

class GameManager : public Singleton<GameManager>
{
public:
	void Initialize();
	bool Loop();
	void Destroy();

	inline float GetDeltaTime() const { return deltaTime; } // inline 함수 : 컴파일 타임에 코드 교체가 일어남

private:
	GameManager() = default;
	// 이전 프레임에서 지금 프레임 간의 시간 간격(초 단위)
	float deltaTime = 0.0f;

	System* systems[2] = { nullptr, };
	ConsoleDoubleBuffer* pRenderer = nullptr;
	Input* pInput = nullptr;

	clock_t lastTime = -1;

	friend class Singleton;		// Singleton 클래스는 private멤버나 protected 멤버에 접근 가능
};

