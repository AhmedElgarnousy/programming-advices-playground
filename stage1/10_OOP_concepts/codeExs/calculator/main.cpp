#include <iostream>

class clsCalculator
{
private:
    int _result{};

    /*
    - 0 -> clear
    - 1 -> add
    - 2 -> subtract
    - 3 -> multiply
    - 3 -> divide
    */
    int _lastOperationStatus{};
    int _lastNumberVal{};

public:
    // clear the calculator
    void Clear(void)
    {
        _result = 0;
        _lastOperationStatus = 0;
        _lastNumberVal = 0;
    }

    // add number
    void Add(int number)
    {
        // number parameter validation check
        // if ((char)number >= 85 || (char)number <= 127)
        // result += number;

        _result += number;
        _lastOperationStatus = 1;
        _lastNumberVal = number;
    }

    void Subtract(int number)
    {
        _result -= number;
        _lastOperationStatus = 2;
        _lastNumberVal = number;
    }
    void Divide(int number)
    {
        if (number == 0)
        {
            _result /= 1;
            _lastNumberVal = 1;
            return;
        }
        _result /= number;
        _lastOperationStatus = 4;
        _lastNumberVal = number;
    }

    void Multiply(int number)
    {
        _result *= number;
        _lastOperationStatus = 3;
        _lastNumberVal = number;
    }

    // print result
    void PrintResult()
    {
        std::cout
            << "Result After " << ((_lastOperationStatus == 0) ? "Clearing " : (_lastOperationStatus == 1) ? "Adding "
                                                                           : (_lastOperationStatus == 2)   ? "Subtract "
                                                                           : (_lastOperationStatus == 3)   ? "Multiply "
                                                                           : (_lastOperationStatus == 4)   ? "Divide "
                                                                                                           : " error");

        std::cout << _lastNumberVal << " is: " << _result << "\n";
    }

    // handling divide by zero
    // handled by dividing to 1
};

int main()
{
    clsCalculator calc1;

    // calc1.
    calc1.Clear();

    calc1.Add(10);
    calc1.PrintResult();

    calc1.Add(100);
    calc1.PrintResult();

    calc1.Subtract(20);
    calc1.PrintResult();

    calc1.Divide(0);
    calc1.PrintResult();

    calc1.Divide(2);
    calc1.PrintResult();

    calc1.Multiply(3);
    calc1.PrintResult();

    // system("pause>0"); // windows dependent
    // std::cin.get();

    return 0;
}