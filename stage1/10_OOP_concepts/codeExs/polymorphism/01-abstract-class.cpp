#include <iostream>

using std::string;

class clsMobile
{
private:
    virtual void Dial(string PhoneNumber) = 0;
    virtual void SendSMS(string PhoneNumber, string Text) = 0;
    virtual void TakePicture() = 0;

public:
};

class clsIPhone : public clsMobile
{
public:
    void Dial(string PhoneNumber) {}
    void SendSMS(string PhoneNumber, string Text) {}
    void TakePicture() {}
};

int main()
{
    // clsMobile M1; // can't create an oobject of abstract class
    clsIPhone iphone17; // if you forget to implement one of the interfaces, error pure function has no overrider caused
    iphone17.SendSMS("020002", "pop");

    return 0;
}
