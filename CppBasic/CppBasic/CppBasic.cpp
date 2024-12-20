#include <iostream> // F12로 선언을 확인할 수 있다.
#include "Test.h"


using namespace std;    // std 네임스페이스를 기본적으로 사용한다고 표시

int main()  // main 함수(엔트리포인트)
{
	Test day;
	// day.Test_1219_InputOutput();
	// day.Test_1219_DataType();
	// day.Test_1219_ArithmeticOperator();
	// day.Test_1220_Assignment();
	// day.Test_1220_Comparison();
	// day.Test_1220_Logical();
	
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
	
	weaponAvailable = (weaponData & Bow) != Bow;
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
	};

	
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
