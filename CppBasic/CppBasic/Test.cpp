#include "Test.h"
#include <algorithm>
#include <iostream>

// 정의부
using namespace std;

void Test::Run()
{
}

void Test::Run2()
{
}

void Test::Test_1219_InputOutput()
{
    std::string name;
    int number = 10;
    float fNumber = 10.0f;

    //std::cin >> number;     // C++ 표준 입력 방식
    //scanf_s("%d", &number);       
    std::cin >> name;

    //std::cout << "Hello World! " << number <<"\n";  // C++의 표준 콘솔 출력 방식
    //printf("Hello World! %d\n", fNumber);   // C언어의 표준 출력 방식 (%d:정수, %f:실수)
    //printf("Hello World! %f\n", fNumber);
    //std::cout << "My name is " << name << ".\n";
    printf("My name is %s.\n", name.c_str());
}

void Test::Test_1219_DataType()
{
	// 1 bit = 0 아니면 1만 저장 가능
	// 1 Byte = 8bit
	// 1 KByte = 1024 Byte

	int i = 0;	// 인티저 변수 i를 선언함. integer : 부호있는 정수. 소수점 없는 숫자. 32bit 크기
	cout << "Integer Size : " << sizeof(i) << " Byte" << endl;
	unsigned int j = 5000000000;	// 오버플로우 발생
	i = 20;

	float f = 0.0f;	// 플로트 변수 f를 선언함. float : 실수. 소수점 있는 숫자. 32bit 크기. 태생적으로 오차가 있는 데이터타입
	cout << "Float Size : " << sizeof(f) << " Byte" << endl;
	// 12.5 = 125 * 10^-1

	char c;	// 캐릭터 변수 c를 선언함. 정수형, 8bit
	c = 'a';		// 97
	c = 'a' + 1;	// 'b'
	cout << "char Size : " << sizeof(c) << " Byte" << endl;

	bool b;	// 불리언, 8bit
	b = true;
	b = false;
	cout << "bool Size : " << sizeof(b) << " Byte" << endl;

	// 스트링, 가변 사이즈
	std::string str = "String";

	double d = 1.0;	// 실수, 64bit

	// 컴파일 타임에 컴파일러가 추측해서 데이터타입을 결정
	auto a = 10.5;
	cout << "Auto Size : " << sizeof(a) << " Byte" << endl;

	// 상수 : 변할 수 없는 숫자. 컴파일 타임에 결정
	const int con = 0;
	//con = 10;	// 상수는 수정할 수 없다.

	float pi = PI;	//float pi = 3.141592;	// 컴파일러 입장에서는 같음
}

void Test::Test_1219_ArithmeticOperator()
{
	// 산술연산자
	int a = 10;
	int b = 20;
	int c = a + b;
	auto d = c + 10.5f;			// 암시적 캐스팅 : int와 float을 연산한 결과는 암시적으로 float으로 변화한다.

	float aa = (int)(10 + 10.5f);	// 명시적 캐스팅 : int로 강제 캐스팅. aa에는 20이 저장됨

	c = a - b;
	c = a * b;
	c = a / b;

	// 10.0f * 0.1f  = 1.0f		// 나누기보다는 곱하기가 빠르다.
	// 10.0f / 10.0f = 1.0f

	a = 7;
	b = 3;
	c = a % b;	// 나머지를 구하는 연산

	// % : modulo. 나머지 구하기
	c = a - (b * (a / b));

	// 4GHz = 4000MHz = 4000000KHz = 4000000000 Hz
	
	int end = 0;
}
void Test::Test_1220_Assignment()
{
	// 대입연산자 : 변수에 값을 넣어주는 연산자
	int a = 10; // a라는 변수에 10이라는 값을 대입함
	int b = a;
	b += a; // b = b + a;
	b -= a; // b = b - a;
	b *= a; // b = b * a;
	b /= a; // b = b / a;

	// 증감연산자
	a = 10;
	a++;		// a = a + 1;	값을 사용하고 증가
	++a;		// a = a + 1;	값을 사용하지 않고 증가
	a--;		// a = a - 1;

	b = a++;	// b에 a를 먼저 대입하고 a를 1증가
	b = ++a;	// a에 먼저 1증가시키고 b에 대입

	a++;
	b = a;

	// 예전에는 성능 차이 for(int i=0;i<10;i++) < for(int i=0;i<10;++i) 그러나 지금은 컴파일러가 최적화하기 때문에 상관없음
}
void Test::Test_1220_Comparison()
{
	// 비교 연산자(크다, 작다, 같다, 다르다)
	int a = 10;
	int b = 10;

	bool result = false;

	// == : 왼쪽에 있는 값과 오른쪽에 있는 값이 같으면 true, 다르면 false를 돌려주는 연산자
	result = (a == b); // result = true;

	b = 20;
	result = (a == b);		// result = false;

	// != : 왼쪽에 있는 값과 오른쪽에 있는 값이 다르면 true, 같으면 false를 돌려주는 연산자
	result = (a != b);		// result = true;
	b = 10;
	result = (a != b);		// result = false;

	a = 10;
	b = 20;

	result = (a > b);		// result = false;
	result = (a < b);		// result = true;

	b = 10;
	result = (a >= b);		// result = true; 실제 코드 작성 시
	result = (a <= b);		// result = true; 이상, 이하는 피하라 연산 두 번 하기 때문에(평균 두 배 이상) 큰 건 아니지만 아껴서 나쁠 건 없다.
}
void Test::Test_1220_Logical()
{
	// 논리 연산자 : 참, 거짓을 판단하는 연산자
	// && : and. 왼쪽에 있는 값과 오른쪽에 있는 값이 모두 true일 때 true이다.

	bool result;
	result = true && true;		// result = true
	result = true && false;		// result = false
	result = false && true;		// result = false
	result = false && false;	// result = false

	result = true && ture && ture && false; // result = false

	// || : or. 왼쪽에 있는 값이나 오른쪽에 있는 값 중 하나만 true면 true이다
	result = true || true;		// result = true
	result = true || false;		// result = true
	result = false || true;		// result = true
	result = false || false;	// result = true

	result = false || false || ture || false; // result = true

	// 계산이 빨리 끝나는 항목을 항상 앞쪽에 넣는 것이 좋다.

	// ! : not. true는 false로 false는 true로 변경.
	result != true;
	result != false;
}
void Test::Test_1220_Bitwise()
{
	// 비트 연산자 : 비트에 대한 연산
	// & : and. 양변의 숫자의 자리수별로 둘다 1이면 1, 아니면 0
	//  b_0010
	//  b_0111
	// &b_0010

	int i = 2;		// 0000 0000 0000 0000 0000 0000 0000 0010
	int j = 7;		// 0000 0000 0000 0000 0000 0000 0000 0111
	int k = i & j;	// k = 2

	// | : or. 양변의 숫자의 자리수별로 하나라도 1이면 1, 둘다 0이면 0
	k = i | j;		// k = 7

	// ~ : not
	k = ~i;			// 1111 1111 1111 1111 1111 1111 1111 1101 // k의 결과

	// ^ : xor(exclusive or). 다르면 1
	k = i ^ j;		// 0000 0000 0000 0000 0000 0000 0000 0101

	// << : 왼쪽 쉬프트
	k = i << 2;		// 0000 0000 0000 0000 0000 0000 0000 1000
	k = ~i << 2;	// 1111 1111 1111 1111 1111 1111 1111 0100

	// >> : 오른쪽 쉬프트
	k = i >> 2;		// 0000 0000 0000 0000 0000 0000 0000 0000
	int end;

	bool data;		// 1바이트로 참 거짓 중 하나만 저장
	int weaponData = 0;
	// 0000 0000 0000 0000 0000 0000 0000 0000
	// 비트마스크
	unsigned int sw = 0b0001; // 첫번째 : 칼		// 0001
	unsigned int ax = 0b0010; // 두번째 : 도끼	// 0010
	unsigned int sp = 0b0100; // 세번째 : 창		// 0100
	unsigned int bo = 0b1000; // 네번째 : 활		// 1000

	const unsigned char Sword = 1;	// 1 << 0;
	const unsigned char Axe = 2;	// 1 << 1;
	const unsigned char Spear = 4;	// 1 << 2;
	const unsigned char Bow = 8;	// 1 << 3;
	// 내 캐릭터가 칼과 도끼를 사용할 수 있다. : 0011
	weaponData = Sword | Axe;

	// 무기 종류별 비트마스크와 weaponData의 & 결과로 판단할 수 있다.
	bool weaponAvailable = (weaponData & Sword) != 0;		// Sword를 사용할 수 있으면 true아니면 false
	weaponAvailable = (weaponData & Sword) == Sword;		// 위와 같은 코드

	/*weaponAvailable = (weaponData & Bow) != Bow;
	if (Sword && weaponData) {
		cout << "sword use" << sw << endl;
	};
	if (Axe && weaponData) {
		cout << "axe use" << ax << endl;
	};
	if (Spear && weaponData) {
		cout << "spear use" << sp << endl;
	};
	if (Bow && weaponData) {
		cout << "bow use" << bo << endl;
	};
	if(0 && weaponData){
		cout << "no use" << endl;
	};*/
}
void Test::Test_1220_ControlStatement()
{
	// 제어문(Control statement)
	int a = 10;

	if (a > 5)
	{
		// 조건이 true일 때 실행
	}
	else
	{
		// 조건이 false일 때 실행
	}

	if (a < 5)
	{
		// a가 5보다 작으면 실행
	}

	if (a < 5)
	{
		// a가 5보다 작을 때 실행
	}
	else if (a < 10)
	{
		// a가 5보다 크거나 같고 10보다 작을 때 실행
	}

	switch (a)
	{
	case 1:
		printf("1\n");
		break;
	case 2:
		printf("2\n");
		break;
	case 3:
		printf("3\n");
		break;
	default:
		printf("Default\n");
		break;
	}

	// 반복문(Loop)
	int i = 0;
	while (i < 11) // 조건을 확인하고 조건이 참이면 {} 안의 코드를 수행. 총 11번 실행
	{
		i++;
	}

	i = 0;
	while (true)	// 무한 루프의 경우 루프를 탈출하는 조건을 반드시 설정해야 한다. 총 11번 실행
	{
		i++;
		if (i > 10)
		{
			break;
		}
	}

	i = 0;
	do
	{
		i++;
	} while (i < 11);	// 일단 {} 사이의 코드를 한 번 실행하고 조건을 확인한 후 조건이 참이면 다시 실행. 총 10번 실행

	for (int j = 0; j < 10; j++)	// j<10 조건을 확인하고 조건이 참이면 {}사이 코드 실행. 총 10번 실행
	{
		if (j % 2 == 0) // 짝수는 처리하지 않고 스킵
			continue;	// 이 이후의 코드는 실행하지 않고 loop의 시작점으로 돌아가기

		printf("%d is odd", j);	// 홀수는 홀수라고 출력하고 짝수는 아무것도 안함
	}
	printf("Input number : ");
	cin >> a;
	if (a % 2 == 0)
	{
		printf("%d is even.\n", a);
	}
	else
	{
		printf("%d is odd.\n", a);
	}
	int number = 0, odd = 0, even = 0;
	std::cin >> number;
	if ((number % 2) == 0)
	{
		number = even;
		printf("even number %d.\n", even);
	}
	else {
		number = odd;
		printf("odd number %d.\n", odd);
	}
}
void Test::Test_1220_SlotMachine()
{
	// 슬롯머신
	// 처음에 돈을 걸고
	// 랜덤으로 숫자를 3개 뽑아서 셋다 같은 숫자가 나오면 2배로 돌려주기
	// 다시 처음으로

	int money = 100000;	// 게임 시작 시 보유 금액
	const int WinRate = 100; // 당첨 시 배율
	while (true) // 게임을 재시작하기 위한 루프
	{
		std::srand(std::time(0)); // 랜덤 숫자 생성을 위한 시드 설정
	
		// 현재 베팅한 돈
		int bet = 0;
		
		cout << "베팅 금액을 입력하세요(" << money << "원 보유 중): ";
		cin >> bet;	// 입력 받고
		if (bet > 0 && bet <= money)
		{
			// 베팅 금액이 0보다 크고 가지고 있는 돈보다 작거나 같을 때
			cout << "슬롯머신을 시작합니다!" << endl;
			int slot1 = std::rand() % 10;
			int slot2 = std::rand() % 10;
			int slot3 = std::rand() % 10;
			
			// 테스트용으로 7로 고정
			// slot1 = slot2 = slot3 = 7;

			cout << "첫 번째 숫자: " << slot1 << endl;
			cout << "두 번째 숫자: " << slot2 << endl;
			cout << "세 번째 숫자: " << slot3 << endl;

			money -= bet;	// 베팅한 만큼 돈을 뺀다.
			
			if (slot1 == slot2 && slot2 == slot3)
			{
				int win = bet * WinRate;
				money += win;	// 당첨 금액을 추가한다
				cout << "축하합니다! 당첨 금액: " << win << "원" << endl;
			}
			else
			{
				cout << "안타깝지만, 다시 도전해 보세요! 남은 금액: " << money << "원" << endl;
		}
	} else { cout << "베팅 금액이 잘못되었습니다. 다시 입력하세요." << endl; continue;
	// 잘못된 금액 입력 시 재입력 받도록
	continue }
	if (money <= 0) {
		cout << "돈이 모두 소진되었습니다. 게임을 종료합니다." << endl;
		break;
	} char playAgain;
	cout << "다시 플레이하시겠습니까? (y/n): ";
	cin >> playAgain;
	if (playAgain != 'y') { 
		break; // 사용자가 다시 플레이하지 않으면 루프 종료
	}
	} return 0;
}
void Test::Test_1220_RPS()
{
	std::srand(std::time(0));

	// 가위바위보
	// 3선승

	const int Rock = 1;
	const int Paper = 2;
	const int Scissors = 3;

	int myWinCount = 0;
	int enemyWinCount = 0;

	while (myWinCount < 3 && enemyWinCount < 3)
	{
		int mySelection = 0;
		string selectText = "";

		while (mySelection < 1 || mySelection > 3)
		{
			printf("Select Rock(1) Paper(2) Scissors(3) : ");
			cin >> mySelection;		// 나의 선택

			switch (mySelection)
			{
			case 1:
				selectText = "Rock";
				break;
			case 2:
				selectText = "Paper";
				break;
			case 3:
				selectText = "Scissors";
				break;
			default:
				break;
			}
		}

		printf("Your select is [%s]\n", selectText.c_str());	// 나의 선택 출력
		int enemySelection = (rand() % 3) + 1;
		switch (enemySelection)
		{
		case 1:
			selectText = "Rock";
			break;
		case 2:
			selectText = "Paper";
			break;
		case 3:
			selectText = "Scissors";
			break;
		}
		printf("Enemy select is [%s]\n", selectText.c_str());	// 나의 선택 출력

		switch (mySelection)
		{
		case 1:
			switch (enemySelection)
			{
			case 1:
				// 무승부
				printf("Draw\n");
				break;
			case 2:
				// 적의 승리
				enemyWinCount++;
				printf("ENEMY WIN\n");
				break;
			case 3:
				// 나의 승리
				myWinCount++;
				printf("YOU WIN\n");
				break;
			}
			break;
		case 2:
			switch (enemySelection)
			{
			case 1:
				// 나의 승리
				myWinCount++;
				printf("YOU WIN\n");
				break;
			case 2:
				// 무승부
				printf("Draw\n");
				break;
			case 3:
				// 적의 승리
				enemyWinCount++;
				printf("ENEMY WIN\n");
				break;
			}
			break;
		case 3:
			switch (enemySelection)
			{
			case 1:
				// 적의 승리
				enemyWinCount++;
				printf("ENEMY WIN\n");
				break;
			case 2:
				// 나의 승리
				myWinCount++;
				printf("YOU WIN\n");
				break;
			case 3:
				// 무승부
				printf("Draw\n");
				break;
			}
			break;
		}

		printf("You : [%d], Enemy : [%d]\n", myWinCount, enemyWinCount);
		mySelection = 0;
	}
}

void Test::Test_1220_Template()
{
	int data = Add(1, 3);
	float data2 = Add(1.5f, 3.3f);

	int data3 = TemplateAdd<int>(10, 30);
	float data4 = TemplateAdd<float>(10.5f, 2.6f);

	// 이름 : Clamp
	// 파라미터 : value, min, max
	// 기능 : value가 min보다 작으면 min을 반환, max보다 크면 max를 반환, 아니면 value를 반환하는 함수
	// 템플릿 함수로 구현해야 한다.

	int data5 = Clamp<int>(10, 0, 100);	// 10
	int data6 = Clamp<int>(110, 0, 100);	// 10
}

int array4[4][3] = {	// 배열은 뒤에서부터 해석(3개짜리가 4개 있다.)
	{1,2,3},
	{4,5,6},
	{7,8,9},
	{10,11,12}
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

void TestFunction() // 함수의 정의
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
int add(int num1, int num2)
{
	return num1 + num2;
}
float Add(float num1, float num2)
{
	return num1 + num2;
}

template<typename T>
T TemplateAdd(T num1, T num2)
{
	return num1 + num2;
}
void Test::Test_1220_WeekendHomework()
{
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