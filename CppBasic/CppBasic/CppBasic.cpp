#include <iostream> //  F12로 선언을 확인할 수 있다.
#include "Test.h"
#include <vector>

using namespace std;    // std 네임스페이스를 기본적으로 사용한다고 표시
const int WIDTH = 5;
const int HEIGHT = 5;

enum Direction { UP = 1, DOWN, LEFT, RIGHT };
enum Cell { EMPTY, WALL, GOAL, PLAYER };

void printMaze(const vector<vector<Cell>>& maze, int playerX, int playerY) {
	for (int y = 0; y < HEIGHT; ++y) {
		for (int x = 0; x < WIDTH; ++x) {
			if (x == playerX && y == playerY)
				cout << "P ";
			else if (maze[y][x] == WALL)
				cout << "# ";
			else if (maze[y][x] == GOAL)
				cout << "G ";
			else
				cout << ". ";
		}
		cout << endl;
	}
}

bool movePlayer(int& playerX, int& playerY, Direction direction, const vector<vector<Cell>>& maze) {
	int newX = playerX;
	int newY = playerY;
	switch (direction) {
	case UP: newY--; break;
	case DOWN: newY++; break;
	case LEFT: newX--; break;
	case RIGHT: newX++; break;
	}
	if (newX < 0 || newX >= WIDTH || newY < 0 || newY >= HEIGHT || maze[newY][newX] == WALL)
		return false;

	playerX = newX;
	playerY = newY;
	return true;
}


void TestFunction(int, float); // 함수의 선언 : 리턴값의 타입, 함수 이름, 파라미터의 타입과 이름(0개 이상 가능)

int main()  // main 함수(엔트리포인트)
{
	
	Test day;
	// day.Test_1219_InputOutput();
	// day.Test_1219_DataType();
	// day.Test_1219_ArithmeticOperator();
	// day.Test_1220_Assignment();
	// day.Test_1220_Comparison();
	// day.Test_1220_Logical();
	// day.Test_1220_Bitwise();	
	// day.Test_1220_ControlStatement();
	// day.Test_1220_SlotMachine();
	// day.Test_1220_RPS();
	// day.Test_1220_WeekendHomework();
	// 포인터 : 메모리 주소를 저장하는 변수
	int a = 10;
	int* pAddress = nullptr;
	pAddress = &a; // & : 주소 연산자 &로 a변수의 주소를 가져오기

	int b = *pAddress; // 간접참조연산자 * Address 주소에 들어있는 데이터를 int타입으로 가져오는 것

	int array[5] = { 1,3,5,7,9 };

	pAddress = array;
	// pAddress + 1; array[1]; 같은 동작	
	//*(pAdress + 5) = 30;	// 범위를 벗어나서 접근
	// 같은 종류의 데이터타입이 연속적으로 저장되어 있다.(빠르게 각 요소에 접근할 수 있다.)
	int array1[5];
	array1[0] = 1;
	array1[1] = 10;
	array1[2] = 7;
	array1[3] = 5;
	array1[4] = 20;

	int array2[5] = { 1, 3, 5, 7, 9 };
	//array2[5] = 10; // 크기는 무조건 고정이다.(삽입/삭제가 어렵다)

	int* array3 = array1;

	int array4[4][3] = { // 배열은 뒤에서부터 해석(3개짜리가 4개 있다.)
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
		{10, 11, 12}
	};

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", array2[i]);
	}

	for (int num : array2)
	{
		printf("%d\n", num);
	}
}

	void TestFunction(int number1, float number2) // 함수의 정의
	{
		// 함수의 바디, 코드 블럭

		// 함수가 실행할 기능들 구현

		return; // void는 return이 있어도 되고 없어도 된다.
	}

	int TestFunction2(int number1, float number2) // 함수의 정의
	{
		if (number1 > 1)
			return 1;
		return number1 + number2; // 함수의 종료지점

		printf("Hello"); // return 이후에 있는 코드(이 줄 포함)는 실행되지 않는다.
	}
	int data = Add(1, 3);
	int numberplus(int a, int b)
	{
		return a + b;
	}
	float numberplus(float c, float d)
	{
		return c + d;
	}
    
	
	
}

// F5 : 디버그 모드로 시작
// F10 : 디버그 모드에서 브레이크 포인트에서 멈췄을 때 누르면 브레이크 포인트에서 한 줄씩 진행한다. 
// F7 : 프로그램 빌드
// Shift + Del : 한줄씩 지우기
// Ctrl + D : 한줄 복사
// Ctrl + K + O : 헤더와 소스를 전환하기
// Ctrl + , : Go to All 메뉴 열기
// Ctrl + . : 빠른 작업 및 리팩토링
// Ctrl + Tab : 열려있는 창 이동
