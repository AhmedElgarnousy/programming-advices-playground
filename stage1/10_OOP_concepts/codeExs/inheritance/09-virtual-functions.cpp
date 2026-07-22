#include <iostream>

using std::string;

class clsPerson
{
private:
public:
    virtual void Print()
    {
        std::cout << "I am a Person\n";
    }
};

class clsEmployee : public clsPerson
{
private:
public:
    void Print()
    {
        std::cout << "I am an Employee\n";
    }
};
class clsStudent : public clsPerson
{
private:
public:
    // void Print()
    // {
    //     std::cout << "I am a student\n";
    // }
};

int main()
{

    clsEmployee employee1;
    employee1.Print();

    clsStudent student1;
    student1.Print();

    clsPerson *pPerson1 = &employee1;

    pPerson1->Print();

    clsPerson *pPerson2 = &student1;
    pPerson2->Print();

    return 0;
}