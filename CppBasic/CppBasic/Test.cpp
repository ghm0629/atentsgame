#include "Test.h"
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