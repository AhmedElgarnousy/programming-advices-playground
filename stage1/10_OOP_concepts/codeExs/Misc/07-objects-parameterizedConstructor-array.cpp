#include <iostream>

using namespace std;

class clsA
{
private:
public:
    int id = 0;
    void Print()
    {
        cout << "The value of id=" << id << endl;
    }
    clsA(int idVal)
    {
        this->id = idVal;
    }
};

int main()
{

    int numOfObjs = 3;

    // Initializing 3 array Objects with function calls of
    // parameterized constructor as elements of that array

    clsA arr[] = {clsA(1), clsA(2), clsA(3)};

    // using print method for each of three elements.
    for (int i = 0; i < numOfObjs; i++)
    {
        arr[i].Print();
    }
    return 0;
}
