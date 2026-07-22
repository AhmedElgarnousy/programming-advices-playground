#include <iostream>

class clsPerson
{

public:
    std::string full_name;
    clsPerson()
    {
        full_name = "Ahmed-Kamal";
        std::cout << "Iam the constructor\n";
    }

    ~clsPerson()
    {
        std::cout << "Iam the destructor\n";
    }
};

void test_objects_in_heap()
{
    clsPerson *pPerson = new clsPerson;
    delete pPerson;
}
int main()
{
    // {
    //     clsPerson person1;
    // }
    // here desctructor calls

    test_objects_in_heap();
    getchar();

    return 0;
}