
#include <iostream>

constexpr double PI = 3.14159265358979323846;
using namespace std;

void referesh_screen() 
{
	cout << "\n\nPress Enter to referesh the screen....";
	cin.ignore();
	while (cin.get() != '\n'); // enter key press
	system("cls");
}

void referesh_program(void (*ptrToFunc)())
{
	referesh_screen();
	ptrToFunc();
}

void c2_problem_n7() 
{
	int num;
	while (1)
	{
		system("cls");
		cout << "Enter a number: ";
		cin >> num;

		referesh_screen();
	}
}

void c2_problem_n10() 
{
	int mark1, mark2, mark3, average;
	cout << "Enter three marks: ";
	cin >> mark1 >> mark2 >> mark3;

	average = (mark1 + mark2 + mark3) / 3;

	cout << "The average of the three marks is: " << average << endl;

	referesh_screen();
}

void c2_problem_n9() {
	int num1, num2, num3;

	while (1)
	{
		cout << "Enter three numbers: ";
		cin >> num1 >> num2 >> num3;

		cout << " sum of the three numbers is: " << num1 + num2 + num3 << endl;

		referesh_screen();
	}
}

void c2_problem_n14() 
{
	int num1, num2, swapVal;
	cout << "Please Enter 2 numbers: ";
	cin >> num1 >> num2;

	swapVal = num1;
	num1 = num2;
	num2 = swapVal;

	cout << "after swap, num1 is " << num1 << " num2 is " << num2 << "\n";

	referesh_program(c2_problem_n14);
}

void c2_problem_n15()
{
	int Rectangle_Length, Rectangle_Width, Rectangle_Area;
	cout << "pLease Enter length and Width: ";
	cin >> Rectangle_Length >> Rectangle_Width;

	Rectangle_Area = Rectangle_Length * Rectangle_Width;

	cout << "Rectangle Area is : " << Rectangle_Area;

	referesh_program(c2_problem_n15);
}

void c2_problem_n17()
{
	float Traingle_Base, Traingle_Height, Traingle_Area;

	cout << "pLease Enter Height and Width: ";
	cin >> Traingle_Base >> Traingle_Height;

	Traingle_Area = ((Traingle_Base /2) * Traingle_Height);

	cout << "Traingle Area is : " << Traingle_Area;

	referesh_program(c2_problem_n17);
}

void c2_problem_n19()
{
	float Circle_Diameter, Circle_Area;

	cout << "Please Enter Circle Diameter: ";
	cin >> Circle_Diameter ;

	Circle_Area = (( (Circle_Diameter  * Circle_Diameter) * PI) / 4);

	cout << "Circle Area is : " << Circle_Area;

	referesh_program(c2_problem_n19);
}

void c2_problem_n20()
{
	float Circle_Diameter, Circle_Area;

	cout << "Please Enter Circle Diameter: ";
	cin >> Circle_Diameter;

	Circle_Area = (((Circle_Diameter * Circle_Diameter) * PI) / 4);

	cout << "Circle Area is : " << Circle_Area;

	referesh_program(c2_problem_n20);
}

void c2_problem_n21()
{
	float Circle_Circumference, Circle_Area;

	cout << "Please Enter Circle Circumference: ";
	cin >> Circle_Circumference;

	Circle_Area = (Circle_Circumference * Circle_Circumference / (4 * PI) );

	cout << "Circle Area is : " << Circle_Area;

	referesh_program(c2_problem_n21);
}

void c2_problem_n22()
{
	// the formula for the area of a circle inscribed in an isosceles triangle is given by:
	// Validation: Isosceles_Triangle_Base should be > 0 &&  < 2 * Isosceles_Triangle_len
	
	float  Circle_Area, Isosceles_Triangle_Base, Isosceles_Triangle_len;
	cout << "PLease Enter Isosceles Triangle base and len: ";
	cin >> Isosceles_Triangle_Base >> Isosceles_Triangle_len;

	Circle_Area = 
		
		(PI *Isosceles_Triangle_Base * Isosceles_Triangle_Base / 4 ) 
		* 
		( 
		(2 * Isosceles_Triangle_len - Isosceles_Triangle_Base)
		/ 
        (2 * Isosceles_Triangle_len + Isosceles_Triangle_Base) );


	cout << "Circle Area is : " << Circle_Area;

	referesh_program(c2_problem_n22);
}

int power(int base, int power) {
	int res = 1;
	while (power)
	{
		res *= base;
		power--;	
	}
	return res;
}

void c2_problem_n31()
{
	int num;
	cout << "Please Enter a number: ";
	cin >> num;

	cout << "number^2 : " << power(num, 2) << endl;
	cout << "number^3 : " << power(num, 3) << endl;
	cout << "number^4 : " << power(num, 4) << endl;

	referesh_program(c2_problem_n31);
}

enum CoinDenomination
{
	Penny = 1,
	Nickel = 5,
	Dime = 10,
	Quarter = 25,
	Dollar = 100
};

void c2_problem_n35() {

	uint16_t PennyCount, NickelCount, DimeCount, QuarterCount, DollarCount;

	cout << "Please Enter the number of coins for each denomination:\n";
	cin >> PennyCount >> NickelCount >> DimeCount >> QuarterCount >> DollarCount;

	int TotalInPennies = (PennyCount * CoinDenomination::Penny) +
		(NickelCount * Nickel) +
		(DimeCount * Dime) +
		(QuarterCount * Quarter) +
		(DollarCount * Dollar);

	float TotalInDollars = (float)TotalInPennies / 100.0f;

	cout << TotalInPennies << " Pennies " << endl;
	cout << TotalInDollars << " Dollars " << endl;

	referesh_program(c2_problem_n35);
}

void c2_problem_n39() {
	int TotalBill, CashPaid;
	cout << "Please Enter the total bill and cash paid: ";
	cin >> TotalBill >> CashPaid;

	cout << "Change to be returned: " << (((CashPaid - TotalBill) > 0) ? (CashPaid - TotalBill) : 0) << "\n";

	referesh_program(c2_problem_n39);
}

void c2_problem_n40()
{
	int BillValue;
	float salesTax, TotalBill, serviceFees;
	cout << "Please Enter the BillValue: ";
	cin >> BillValue;

    TotalBill = (float)BillValue;
	serviceFees = (float)BillValue * 0.1;
	TotalBill += serviceFees;
	salesTax = TotalBill * 0.16;
	TotalBill += salesTax;

	cout << " TotalBill is " << TotalBill << endl;

	referesh_program(c2_problem_n40);
}

enum enToSeconds {
	DayInSeconds = 24* 60 * 60,
	HourInSeconds = 60 * 60,
	MinInSeconds = 60
};

void c2_problem_n42() 
{
	float daysCount, hoursCount, minutesCount, secondsCount;

	cout << "Please Enter daysCounts, hoursCount, minutesCount, secondsCount: ";
	cin >> daysCount >> hoursCount >> minutesCount >> secondsCount;


	double totalSeconds = daysCount * DayInSeconds + hoursCount * HourInSeconds
		+ minutesCount * MinInSeconds + secondsCount;

	cout << "Total Seconds of task Duration: " << totalSeconds << endl;

	referesh_program(c2_problem_n42);
}

void c2_problem_n43_v1() 
{
	unsigned int NumberOfSeconds;
	cout << "Please Enter a number of seconds: ";
	cin >> NumberOfSeconds;

	unsigned int daysCount = NumberOfSeconds / DayInSeconds;

	// Update with Remaining Seconds
	NumberOfSeconds -= daysCount * DayInSeconds;
	unsigned int HoursCount = NumberOfSeconds / HourInSeconds;

	// Update with Remaining Seconds
	NumberOfSeconds -= HoursCount * HourInSeconds;
	unsigned int MinutesCount = NumberOfSeconds / MinInSeconds;

	// Update with Remaining Seconds
	NumberOfSeconds -= MinutesCount * MinInSeconds;
	unsigned int SecondsCount = NumberOfSeconds;

	cout << daysCount << ":" << HoursCount << ":" << MinutesCount << ":" << SecondsCount << endl;

	referesh_program(c2_problem_n43_v1);
}

void c2_problem_n43_v2()
{
	unsigned int NumberOfSeconds;
	cout << "Please Enter a number of seconds: ";
	cin >> NumberOfSeconds;

	unsigned int daysCount = NumberOfSeconds / DayInSeconds;

	//NumberOfSeconds -= daysCount * DayInSeconds; // Update with Remaining Seconds
	unsigned int HoursCount = (NumberOfSeconds % DayInSeconds) / HourInSeconds;

	
	//NumberOfSeconds -= HoursCount * HourInSeconds; // Update with Remaining Seconds
	unsigned int MinutesCount = (NumberOfSeconds % HourInSeconds) / MinInSeconds;

	//NumberOfSeconds -= MinutesCount * MinInSeconds; // Update with Remaining Seconds
	unsigned int SecondsCount = NumberOfSeconds % MinInSeconds;

	cout << daysCount << ":" << HoursCount << ":" << MinutesCount << ":" << SecondsCount << endl;

	referesh_program(c2_problem_n43_v2);
}

void c2_problem_n47(){

	referesh_program(c2_problem_n47);
}
void c2_problem_n48(){

	referesh_program(c2_problem_n48);
}


int main()
{
	/*
	 programs doesn't have error handling mechanism to user inputs
	 just run one program to test it
	*/

	//c2_problem_n7();
	//c2_problem_n9();
	//c2_problem_n10();
	//c2_problem_n14();
	//c2_problem_n15();
	//c2_problem_n17();
	//c2_problem_n19();
	//c2_problem_n21();
	//c2_problem_n22();
	//c2_problem_n31();
	//c2_problem_n32();
	//c2_problem_n35();
	//c2_problem_n39();
	//c2_problem_n40();
	//c2_problem_n42();
	//c2_problem_n43_v1();
	c2_problem_n43_v2();


	//c2_problem_n47();
	//c2_problem_n48();


	
	return 0;
}
