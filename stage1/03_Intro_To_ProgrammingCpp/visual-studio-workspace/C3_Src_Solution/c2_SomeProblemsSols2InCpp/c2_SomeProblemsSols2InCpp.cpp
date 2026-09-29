

#include <iostream>
#include <cmath>


using namespace std;

constexpr double PI = 3.14159265358979323846;

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

void c2_problem_n16()
{
	float diagonal, side_area, rectangle_area;

	cout << "Please Enter the side area and diagnoal: ";
	cin >> side_area >> diagonal;

	rectangle_area = side_area * sqrt( pow(diagonal, 2) - pow(side_area, 2) );

	cout << "Rectangle Area: " << rectangle_area << endl;

	referesh_program(c2_problem_n16);
}


void c2_problem_n18()
{
	float diamter, area;

	cout << "Please Enter a circle Diamter: ";
	cin >> diamter;

	area = PI * pow(diamter, 2);

	cout << "circle area: " << area << endl;

	referesh_program(c2_problem_n18);

}

void c2_problem_n19() {

	float diamter, circle_area;

	cout << "enter a circle diamter: ";
	cin >> diamter;

	circle_area = PI * pow(diamter, 2) / 4;

	cout << "circle area: " << circle_area << endl;

	referesh_program(c2_problem_n19);

}

void c2_problem_n20() 
{
	c2_problem_n19();
}

void c2_problem_n21() 
{
	float circle_circumference, circle_area;

	cout << "please enter the circumference: ";
	cin >> circle_circumference;

	circle_area = pow(circle_circumference, 2) / 4 * PI;

	cout << "circle area: " << floor(circle_area) << endl;
	
}

void c2_problem_n22() 
{
	// the formula for the area of a circle inscribed in an isosceles triangle is given by:
// Validation: Isosceles_Triangle_Base should be > 0 &&  < 2 * Isosceles_Triangle_len

	float  Circle_Area, Isosceles_Triangle_Base, Isosceles_Triangle_len;
	cout << "PLease Enter Isosceles Triangle base and len: ";
	cin >> Isosceles_Triangle_Base >> Isosceles_Triangle_len;

	if (!(Isosceles_Triangle_Base > 0 && Isosceles_Triangle_Base < 2 * Isosceles_Triangle_len))
	{
		cout << "Wrong Dimensions\n";
		return;
	}

	Circle_Area =

		(PI * pow(Isosceles_Triangle_Base ,2) / 4)
		*
		(
			(2 * Isosceles_Triangle_len - Isosceles_Triangle_Base)
			/
			(2 * Isosceles_Triangle_len + Isosceles_Triangle_Base));


	cout << "Circle Area is : " << floor(Circle_Area);
}

void c2_problem_n23() 
{
	float triangle_len1, triangle_len2, triangle_len3;
	float triangle_area;

	cout << "Please Enter 3 different triangle_len: ";
	cin >> triangle_len1 >> triangle_len2 >> triangle_len3;

	float p = (triangle_len1 + triangle_len2 + triangle_len3 ) / 2.0f;

	float T = (triangle_len1 * triangle_len2 * triangle_len3)
		/ (4.0f * sqrt(p * (p - triangle_len1) * (p - triangle_len2) * (p - triangle_len3)));

	triangle_area = PI * pow(T, 2);


	cout << "Triangle Area: " << round(triangle_area) << endl;

	referesh_program(c2_problem_n23);
}


void c2_problem_n31() 
{
	float number;
	cout << "Please Enter a positive number: ";
	cin >> number;

	cout << round(pow(number, 2)) << "\n";
	cout << round(pow(number, 3)) << "\n";
	cout << round(pow(number, 4)) << "\n";	
}


void c2_problem_n32() {}
void c2_problem_n42() {}
void c2_problem_n43() {}



int main()
{
	//c2_problem_n16();

	//c2_problem_n18();
	//c2_problem_n19();

	//c2_problem_n21();
	//c2_problem_n22();

	//c2_problem_n23();
	c2_problem_n31();
	//c2_problem_n32();
	//c2_problem_n42();
	//c2_problem_n43();


}
