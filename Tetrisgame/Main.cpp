#include <iostream>
#include "GameManager.h"
//#include "ConsoleDoubleBuffer.h"
//#include "Logger.h"

#include "Test.h"

#define _TEST_MODE 1	// 테스트 코드 포함/제거용 디파인

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#ifdef _TEST_MODE		// _TEST_MODE가 디파인되어 있으면 컴파일러에서 포함, 되어 있지 않으면 컴파일러에서 포함하지 않음
	Test test;
	test.Test_Output();
	//test.Test_Input();	// 내부에서 무한 루프를 돌린다.
	test.Test_Logger();
	test.Test_Functional();
	test.Test_Tetromino();
	
	test.Test_Input_Functional();	// 내부에서 무한 루프 돌린다.
#endif	// _TEST_MODE

	GameManager& manager = GameManager::Get();
	manager.Initialize();

#ifdef _TEST_MODE
	test.Test_Input_System();
#endif

	while (true)
	{
		manager.Loop();
	}

	manager.Destroy();

	return 0;
	//ConsoleDoubleBuffer* pDoubleBuffer = new ConsoleDoubleBuffer();
	//pDoubleBuffer->Initialize();
	
	//const char* message = "Hello World!";

	//while (true)
	//{
	//	pDoubleBuffer->Render("Hello World!");
	//	//Sleep(100);
	//	test.Test_Input();
	//}
	//pDoubleBuffer->Destroy();
	//delete pDoubleBuffer;
	//pDoubleBuffer = nullptr;

	// Logger::Get()
	//Logger::Print("Hello");
	//Logger::Print(L"안녕");
}