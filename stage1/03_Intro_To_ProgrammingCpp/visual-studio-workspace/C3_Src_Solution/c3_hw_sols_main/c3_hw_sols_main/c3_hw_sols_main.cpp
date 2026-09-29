
#include <iostream>
#include <sstream>

using namespace std;

enum enIsMarried
{
    Yes = 1,
    No = 0
};
enum enGender {
    Female,
    Male
};

struct stCardInfo
{
public:
    string Name;
    int Age;
    float MonthlySalary;
    float YearlySalary;
    enIsMarried isMarried;
    enGender Gender;
    string City;
    string Country;

    //stCardInfo() {
    //}

    //stCardInfo(string name, int age, string city, string country, float monthlySalary,
    //    enIsMarried is_married, enGender gender)
    //    : Name(name), Age(age), City(city), Country(country),
    //    MonthlySalary(monthlySalary), YearlySalary(monthlySalary * 12),
    //    isMarried(is_married), Gender(gender)
    //{
    //}
};


void WriteCardInfoToConsole(struct stCardInfo* cardInfo)
{
    ostringstream oss;
    oss << "Name: " << cardInfo->Name << "\n"
        << "Age: " << cardInfo->Age << "\n"
        << "City: " << cardInfo->City << "\n"
        << "Country: " << cardInfo->Country << "\n"
        << "Monthly Salary: " << cardInfo->MonthlySalary << "\n"
        << "Yearly Salary: " << cardInfo->YearlySalary << "\n"
        << "Married: " << (cardInfo->isMarried ? "Yes" : "No") << "\n"
        //<<"Married: " << cardInfo->isMarried  <<"\n"
        << "Gender: " << (cardInfo->Gender ? "Male" : "Female") << "\n";

    cout << "****************************\n";
    cout << oss.str();
    cout << "****************************\n";

}

void ReadCardInfo(struct stCardInfo* pStCardInfo)
{
    cout << "Please Enter your Name: ";
    cin >> pStCardInfo->Name;
    cout << "Please Enter your Age: ";
    cin >> pStCardInfo->Age;
    cout << "Please Enter your City: ";
    cin >> pStCardInfo->City;
    cout << "Please Enter your Monthly Salary: ";
    cin >> pStCardInfo->MonthlySalary;
    pStCardInfo->YearlySalary = pStCardInfo->MonthlySalary * 12;
    bool genderIntValue;
    cout << "Please Enter your Gender\n\t 1 for `M`, and 0 for `F`: ";
    cin >> genderIntValue;
    pStCardInfo->Gender = (enGender)genderIntValue;
    cout << "Are you married ?\n\t 1 for `yes`, and 0 for `No`: ";
    bool isMarriedIntValue;
    cin >> isMarriedIntValue;
    pStCardInfo->isMarried = (enIsMarried)isMarriedIntValue;
}


void lesson18_program2()
{
    int num1, num2, num3;
    cout << "Please Enter a first Number: ";
    cin >> num1;
    cout << "Please Enter a second Number: ";
    cin >> num2;
    cout << "Please Enter a third Number: ";
    cin >> num3;

    cout << num1 << "+\n";

    cout << num2 << "+\n";

    cout << num3 << "=\n";

    cout << num1 + num2 + num3 << "\n";

}
struct sizeOfDataTypes
{
    // 4 bytes
    int v1;
    signed int v2;
    unsigned int v3;

	// 2 bytes
    short int v4;
    short v5;

    unsigned short int v6;
    unsigned short v7;

	// 4 bytes
    signed long int v8;
    long int v9;
    long v10;

    unsigned long v11;


    // 8 bytes
    long long int v12;

    unsigned long long v13;

};


void PrintDataTypeSizes()
{
	sizeOfDataTypes dataTypes;
	cout << "Size of int: " << sizeof(dataTypes.v1) << " bytes\n";
	cout << "Size of signed int: " << sizeof(dataTypes.v2) << " bytes\n";
	cout << "Size of unsigned int: " << sizeof(dataTypes.v3) << " bytes\n";
	cout << "Size of short int: " << sizeof(dataTypes.v4) << " bytes\n";
	cout << "Size of short: " << sizeof(dataTypes.v5) << " bytes\n";
	cout << "Size of unsigned short int: " << sizeof(dataTypes.v6) << " bytes\n";
	cout << "Size of unsigned short: " << sizeof(dataTypes.v7) << " bytes\n";
	cout << "Size of signed long int: " << sizeof(dataTypes.v8) << " bytes\n";
	cout << "Size of long int: " << sizeof(dataTypes.v9) << " bytes\n";
	cout << "Size of long: " << sizeof(dataTypes.v10) << " bytes\n";
	cout << "Size of unsigned long: " << sizeof(dataTypes.v11) << " bytes\n";
	cout << "Size of long long int: " << sizeof(dataTypes.v12) << " bytes\n";
	cout << "Size of unsigned long long: " << sizeof(dataTypes.v13) << " bytes\n";
}

void someDatatypesErrors() {
    double distance = 56E12;
	double d2 = 5.6e+13;

	cout << distance << " " << d2 << endl;

	short d = 3434233; // Error: out of range for short, overflow occurs
	cout << d << endl;

	unsigned int a = -10; // Error: negative value for unsigned int
	cout << a << endl;

	unsigned short b = -1; // Error: negative value for unsigned short
    cout << b << endl;

}

void ShowDataTypesRanges() 
{
	cout << "Range of signed char: " << (int)CHAR_MIN << " to " << (int)CHAR_MAX << endl;
	cout << "Range of unsigned char: " << (int)0 << " to " << (int)UCHAR_MAX << endl;
	cout << "Range of signed short: " << SHRT_MIN << " to " << SHRT_MAX << endl;
	cout << "Range of unsigned short: " << 0 << " to " << USHRT_MAX << endl;
	cout << "Range of signed int: " << INT_MIN << " to " << INT_MAX << endl;
	cout << "Range of unsigned int: " << 0 << " to " << UINT_MAX << endl;
	cout << "Range of signed long: " << LONG_MIN << " to " << LONG_MAX << endl;
	cout << "Range of unsigned long: " << 0 << " to " << ULONG_MAX << endl;
	cout << "Range of signed long long: " << LLONG_MIN << " to " << LLONG_MAX << endl;
	cout << "Range of unsigned long long: " << 0 << " to " << ULLONG_MAX << endl;
	cout << "Range of float: " << FLT_MIN << " to " << FLT_MAX << endl;
	cout << "Range of double: " << DBL_MIN << " to " << DBL_MAX << endl;
	cout << "Range of long double: " << LDBL_MIN << " to " << LDBL_MAX << endl;
	cout << "Range of bool: " << false << " to " << true << endl;
   
}


void arithmeticOperations() {
    
    int A , B ;
	cout << "Please Enter two numbers (A and B): ";
	cin >> A >> B;

	cout << "A + B = " << A + B << endl;
	cout << "A - B = " << A - B << endl;
	cout << "A * B = " << A * B << endl;
	cout << "A / B = " << (float)A / (float)B << endl;
	cout << "A % B = " << A % B << endl;

}

int main() {
    //stCardInfo AhmedCard;

    //ReadCardInfo(&AhmedCard);
    //WriteCardInfoToConsole(&AhmedCard);

    //lesson18_program2();
    //someDatatypesErrors();
    //ShowDataTypesRanges();
    arithmeticOperations();

    return 0;

}