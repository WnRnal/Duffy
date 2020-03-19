#include <iostream>
#include "LineSegment.hpp"
#include "EuropeanOption.hpp"
#include "SimpleBondPricing.hpp"

using namespace std;
//int result = 1;
int& FlunkyFunc() {
	int result = 1;
	cout << "Funny";
	return result;
};

class pPoint {
public:
	double& WrongFuncion() {
		double d = 3.1415; return d;
	}
};

int testLineSegment() {
	// #2-1.
	int a = FlunkyFunc();
	cout << a << endl;

	FlunkyFunc() = 12;
	cout << FlunkyFunc() << "eee" << endl;
	// warning C4172: returning address of local variable or temporary: result
	// int& 으로 선언된 FlunkyFunc()는 int형 변수의 주소를 참조하는데, return값으로 반환하는 변수가 FlunkyFunc() 함수 내부의 지역변수이므로 결과적으로 함수 내부 지역변수의 주소를 반환하고 있다.
	// 즉, FlunkyFunc()=12; 와 같이 함수 내 지역변수 result에 값을 할당하여도 다음번에 FlunkyFunc()을 다시 호출할 때 result 변수 값이 1로 초기화되므로 앞서 값을 update한 의미가 없다.

	//#2-2.
	pPoint pt; cout << "Wrong" << pt.WrongFuncion() << endl;
	// warning C4172: returning address of local variable or temporary: d
	// 마찬가지로 함수 내부 지역변수 d의 참조값을 반환하므로 warning.

	// #3.
	Point p1(0.3, 1.7);
	Point p2(2.1, -0.5);
	LineSegment l1(p1, p2);
	l1.print();
	cout << "length of l1: " << l1.length() << endl;
	return 0;
}

int testEuropeanOption() {
	//All Options are European
	//Call option on a stock
	EuropeanOption callOption;
	cout << "Call option on a stock is of price :" << callOption.Price() << endl;

	//Put option on a stock index
	EuropeanOption indexOption;
	indexOption.optType = "P";
	indexOption.U = 100.0;
	indexOption.K = 95.0;
	indexOption.T = 0.5;
	indexOption.r = 0.10;
	indexOption.sig = 0.20;
	double Div = 0.05;
	indexOption.b = indexOption.r - Div;

	cout << "Put option price is :" << indexOption.Price() << endl;

	//Call and put option on a future
	EuropeanOption futureOption;
	futureOption.optType = "P";
	futureOption.U = 19.0;
	futureOption.K = 19.0;
	futureOption.T = 0.75;
	futureOption.r = 0.10;
	futureOption.sig = 0.28;
	futureOption.b = 0.0;

	cout << "Put option on future is of price :" << futureOption.Price() << endl;

	//Change over to a call on the option
	futureOption.toggle();
	cout << "Call option on future is of price :" << futureOption.Price() << endl;

	return 0;
}

using namespace Chapter3CPPBook;
typedef vector<double> Vector;
int testSimpleBondPricing() {
	Vector futureValues(5);

	for (long j = 0; j < 4; j++)
		futureValues[j] = 100.0;
	futureValues[4] = 1100.0;

	int nPeriods = 5;
	double r = 0.0625;
	//cout << "**Present value, series: " << PresentValue(futureValues, nPeriods, r) << endl;
	int i = 2;
	cout << PresentValue(futureValues, nPeriods, r) << endl;
	return 0;
}

#include "GenericInequalities.cpp" // Needed because it is templated (???)
int testGenericInequalities() {
	int d1, d2;
	cout << "Give the first number :";
	cin >> d1;

	cout << "Give the second number : ";
	cin >> d2;

	char c;
	cout << "a. Max()		b. Min()";
	cin >> c;
	if (c == 'a')
		cout << "Maximum of the two numbers is : " << Max<int>(d1, d2) << endl;
	else
		cout << "Minimum of the two numbers is : " << Min<int>(d1, d2) << endl;

	long dA = 12334; long dB = 2; long dC = -3;
	cout << "\n\n Max and Min of three numbers :" << dA << ", " << dB << ", " << dC << endl;
	cout << "Max = " << Max<int>(dA, dB, dC) << endl;
	cout << "Min = " << Min<int>(dA, dB, dC) << endl;

	return 0;
}

int main()
{
	testLineSegment();
	testEuropeanOption();
	testSimpleBondPricing();
	testGenericInequalities();

	return 0;
}