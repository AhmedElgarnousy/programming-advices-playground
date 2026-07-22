#include <iostream>
#include <vector>

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

    vector<clsA> v1;

    int numOfObjs = 5;
    // v1.push_back(clsA());

    for (int i = 0; i < numOfObjs; i++)
    {
        v1.push_back(clsA(i));
    }

    for (int i = 0; i < numOfObjs; i++)
    {
        v1[i].Print();
    }
    return 0;
}
