#include <iostream>
using namespace std;

class Student
{
    int age = 25;

public:
    Student(int age)
    {
        this->age = age; // data member = parameter
    }

    void show()
    {
        cout << "Age paramter: " << age << endl;
    }
};

int main()
{
    Student s(20);
    s.show();

    return 0;
}