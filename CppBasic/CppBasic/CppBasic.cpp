#include <iostream> //  F12로 선언을 확인할 수 있다.
#include "Test.h"
#include <vector>
#include "Animal.h"
#include "LinkedList.h"
#include "BinarySearchTree.h"
#include <queue>
using namespace std;    // std 네임스페이스를 기본적으로 사용한다고 표시
const int WIDTH = 5;
const int HEIGHT = 5;

enum Direction { UP = 1, DOWN, LEFT, RIGHT };
enum Cell { EMPTY, WALL, GOAL, PLAYER };

struct Point {
    int x, y;
};

void printMaze(const Cell maze[HEIGHT][WIDTH], int playerX, int playerY) {
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

bool movePlayer(int& playerX, int& playerY, Direction direction, const Cell maze[HEIGHT][WIDTH]) {
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

bool BFS(const Cell maze[HEIGHT][WIDTH], int startX, int startY, Point parent[HEIGHT][WIDTH]) {
    queue<Point> q;
    bool visited[HEIGHT][WIDTH] = { false };

    int dx[] = { 0, 0, 1, -1 };
    int dy[] = { 1, -1, 0, 0 };

    q.push({ startX, startY });
    visited[startY][startX] = true;

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < WIDTH && ny < HEIGHT && !visited[ny][nx] && maze[ny][nx] != WALL) {
                parent[ny][nx] = p;  // 부모 노드 설정
                visited[ny][nx] = true;
                q.push({ nx, ny });

                if (maze[ny][nx] == GOAL) {
                    return true;
                }
            }
        }
    }

    return false;
}

void tracePath(Point parent[HEIGHT][WIDTH], int startX, int startY, int goalX, int goalY) {
    cout << "경로: ";
    for (Point at = { goalX, goalY }; at.x != startX || at.y != startY; at = parent[at.y][at.x]) {
        cout << "(" << at.x << ", " << at.y << ") <- ";
    }
    cout << "(" << startX << ", " << startY << ")" << endl;
}


void TestFunction(int, float); // 함수의 선언 : 리턴값의 타입, 함수 이름, 파라미터의 타입과 이름(0개 이상 가능)

int main()  // main 함수(엔트리포인트)
{
	Cell maze[HEIGHT][WIDTH] = {
		{ EMPTY, EMPTY, WALL,  EMPTY, GOAL  },
		{ WALL,  EMPTY, WALL,  EMPTY, WALL  },
		{ EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
		{ WALL,  WALL,  WALL,  WALL,  EMPTY },
		{ PLAYER,EMPTY, EMPTY, EMPTY, EMPTY }
	};

	int playerX = 0;
	int playerY = 4;

	Point parent[HEIGHT][WIDTH];
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			parent[i][j] = { -1, -1 };
		}
	}

	if (BFS(maze, playerX, playerY, parent)) {
		cout << "경로를 찾았습니다!" << endl;
		tracePath(parent, playerX, playerY, 4, 0); // (4, 0)은 목표 지점의 좌표
	}
	else {
		cout << "경로를 찾지 못했습니다." << endl;
	}

	return 0;
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
