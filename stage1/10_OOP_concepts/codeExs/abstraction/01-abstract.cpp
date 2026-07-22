#include <iostream>

class clsShape
{
protected:
    float lenght;
    float width;

public:
    virtual float area(float len, float wid)
    {
        // no implementation
    }
};

class Rectangle : public clsShape
{

public:
    float area(float len, float wid) override
    {
        return len * wid;
    }
};

int main()
{

    return 0;
}