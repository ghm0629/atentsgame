#include <iostream>
#include <Windows.h>
#include <functional>
#include <map>
#include "Test.h"
#include "Logger.h"

void Test::Test_Output()
{
	printf("한글");
	OutputDebugString(L"Print~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	OutputDebugStringA("Print-------------------------\n");
}

void Test::Test_Input()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			Logger::Print("Up press\n");
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			Logger::Print("Down press\n");
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			Logger::Print("Left press\n");
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			Logger::Print("Right press\n");
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			break;
		}
	}
}

void Test::Test_Logger()
{
	//Logger::Get().data;
	Logger::Print("Hello\n");
	Logger::Print(L"안녕\n");

}

void Test_Func1()
{
	Logger::Print("Test_Func1\n");
}

void Test::Test_Functional()
{
	std::function<void()> func;		// 함수를 저장할 수 있는 변수
	func = Test_Func1;		// func에 Test_Func1 함수를 저장
	func();					// func에 저장된 함수를 실행

	func = []() {			// 람다함수를 저장
		Logger::Print("Test Lambda Func\n");
	};
	func();

	/*std::function<void()> func2;
	int x = 10;
	func2 = [x]() {
		Logger::Print("Test Lambda Func\n");
		// 만들어지는 타이밍에 x가 캡쳐된다.
		};

	x = 20;
	func2();	// x는 10으로 처리

	[x]() -> float {
		Logger::Print("Test Lambda Func\n");
		return 0.5f;
		};*/

	func = std::bind(&Test::Test_Logger, this);	// 맴버 함수를 저장하기(어떤 인스턴스의 함수인지 알려주어야 한다)
	func();
}

void Test::Test_Input_Functional()
{
	// 화살표 키를 눌렀을 때 적절한 함수가 실행되게 하기
	// 위쪽 : Test_Up() 실행
	// 아래쪽 : Test_Down() 실행
	// 왼쪽 : 람다 함수 실행
	// 오른쪽 : 람다 함수 실행

	// 각각의 함수는 Logger로 방향 출력하기
	// 도전 : 누르기와 때기 구분하기
	std::map<int, std::function<void()>> actions;
	actions[VK_UP] = std::bind(&Test::Test_Up, this);
	actions[VK_DOWN] = std::bind(&Test::Test_Down, this);
	actions[VK_LEFT] = []() {
		Logger::Print("Left press\n");
	};
	actions[VK_RIGHT] = []() {
		Logger::Print("Right press\n");
	};

	bool isUpPress = false;

	while (true)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000)	//UP키가 눌려져 있으면 true, 아니면 false
		{
			if (isUpPress == false)
			{
				// 안눌려져 있다가 이제 눌려졌다.
				isUpPress = true;
				actions[VK_UP]();	// 눌린 직후에만 실행
			}
		}
		else
		{
			if (isUpPress == true)
			{
				// 눌려져 있다가 이제 떨어졌다.
				isUpPress = false;
				actions[VK_UP]();	// 떨어진 직후에만 실행
			}
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			actions[VK_DOWN]();
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			actions[VK_LEFT]();
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			actions[VK_RIGHT]();
		}
	}
}

void Test::Test_Up()
{
	Logger::Print("Up press\n");
}

void Test::Test_Down()
{
	Logger::Print("Down press\n");
}

