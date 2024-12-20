#include <iostream>
#include <vector>
using namespace std;

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

int main() {
    vector<vector<Cell>> maze = {
        { EMPTY, EMPTY, WALL,  EMPTY, GOAL  },
        { WALL,  EMPTY, WALL,  EMPTY, WALL  },
        { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
        { WALL,  WALL,  WALL,  WALL,  EMPTY },
        { PLAYER,EMPTY, EMPTY, EMPTY, EMPTY }
    };

    int playerX = 0;
    int playerY = 4;

    while (maze[playerY][playerX] != GOAL) {
        printMaze(maze, playerX, playerY);
        cout << "이동 방향을 입력하세요 (상: 1, 하: 2, 좌: 3, 우: 4): ";
        int input;
        cin >> input;

        if (input < 1 || input > 4) {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
            continue;
        }

        if (!movePlayer(playerX, playerY, static_cast<Direction>(input), maze)) {
            cout << "이동할 수 없습니다. 다시 시도하세요." << endl;
        }
    }

    cout << "축하합니다! 골인지점에 도착했습니다!" << endl;
    return 0;
}
