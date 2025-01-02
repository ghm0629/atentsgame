#include <iostream> //  F12로 선언을 확인할 수 있다.
#include "Test.h"
#include <vector>
#include "Animal.h"
#include "LinkedList.h"
#include "BinarySearchTree.h"
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
	// day.Test_1223_Pointer();
	// day.Test_1223_Reference();
	// day.Test_1223_String();
	// day.Test_1223_StringPractice();

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
