// 선언부

#define PI 3.141592		// 매크로 : 컴파일 할 때 PI라는 글자가 3.141592로 자동 변경된다.

class Test
{
public:
	int data = 0;

	void Run();
	void Run2();

	void Test_1219_InputOutput();
	void Test_1219_DataType();
	void Test_1219_ArithmeticOperator();
	void Test_1220_Assignment();
	void Test_1220_Comparison();
	void Test_1220_Logical();
	void Test_1220_Bitwise();
	void Test_1220_ControlStatement();
	void Test_1220_SlotMachine();
	void Test_1220_RPS();
	void Test_1220_Template();
	void Test_1220_Array();
	void Test_1220_WeekendHomework();

	void TestFunction(int, float); // 함수의 선언 : 리턴값의 타입, 함수 이름, 파라미터의 타입과 이름(0개 이상 가능)
	int TestFunction2(int, float);

	int Add(int num1, int num2);
	float Add(float num1, float num2);
	
	template <typename T>
	T TemplateAdd(T num1, T num2);
};