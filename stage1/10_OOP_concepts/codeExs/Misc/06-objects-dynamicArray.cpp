#include <iostream>
// #include <vector>

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

    clsA()
    {
    }
    clsA(int idVal)
    {
        this->id = idVal;
    }
};

int main()
{

    int numOfObjs = 5;
    clsA *pClsArr = new clsA[numOfObjs];

    // v1.push_back(clsA());

    for (int i = 0; i < numOfObjs; i++)
    {
        // pClsArr[i].id = i;
        pClsArr[i] = clsA(i);
    }

    for (int i = 0; i < numOfObjs; i++)
    {
        pClsArr[i].Print();
    }

    delete[] pClsArr;
    return 0;
}
