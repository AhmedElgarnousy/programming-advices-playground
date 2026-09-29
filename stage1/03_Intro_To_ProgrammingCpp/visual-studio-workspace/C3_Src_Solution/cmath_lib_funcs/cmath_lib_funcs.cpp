
#include <iostream>
#include <cmath>

using namespace std;


void squareRootFunc() {
	double x = 64;
	cout << "Sqrt of " << x << " is " << sqrt(x) << endl;
}

void roundFunc() 
{
	cout << round(2.4) << endl;  // 2
	cout << round(2.5) << endl;  // 3
	cout << round(-2.5) << endl;  // 2
	cout << round(2.7) << endl;  // 3


	cout << sqrt(50) << endl; // 7.07107

	cout << round(sqrt(50)) << endl; // 7

	cout << round(2.4) + round(2.3) << endl;
}

void powerFunc() 
{
	int base = 2;
	int power = 4;

	cout << pow(base, power);
}

void ceil_floor_funcs() {
	
	cout << ceil(2.1) << endl; // 3
	cout << ceil(2.5) << endl; // 3
	cout << ceil(2.9) << endl; // 3


	cout << floor(2.1) << endl; // 2
	cout << floor(2.5) << endl; // 2
	cout << floor(2.9) << endl; // 2

	cout << ceil(-2.1) << endl; // -2
	cout << ceil(-2.5) << endl; // -2
	cout << ceil(-2.9) << endl; // -2


	cout << floor(-2.1) << endl; // -3
	cout << floor(-2.5) << endl; // -3
	cout << floor(-2.9) << endl; // -3

}

void absFunc() {
	cout << abs(-10) << endl;
	cout << abs(10) << endl;

}


int main() 
{
	//squareRootFunc(x);	
	//roundFunc();
	//powerFunc();
	//ceil_floor_funcs();

	absFunc();

    return 0;
}
