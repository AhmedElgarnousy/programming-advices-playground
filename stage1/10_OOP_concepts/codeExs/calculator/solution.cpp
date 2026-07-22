#include <iostream>
// #include <string>

class clsCalculator
{
private:
    int _result{};
    std::string _lastOperationStatus{};
    int _lastNumberVal{};
    int _previousResult{};

public:
    // clear the calculator
    void Clear(void)
    {
        _result = 0;
        _lastOperationStatus = "clear";
        _lastNumberVal = 0;
    }

    // add number
    void Add(int number)
    {
        _previousResult = _result;
        _lastOperationStatus = "adding";
        _lastNumberVal = number;
        _result += number;
    }

    void Subtract(int number)
    {
        _previousResult = _result;
        _lastOperationStatus = "subtract";
        _lastNumberVal = number;
        _result -= number;
    }
    void Divide(int number)
    {
        if (number == 0)
        {
            _result /= 1;
            _lastNumberVal = 1;
            return;
        }
        _previousResult = _result;
        _lastOperationStatus = "divide";
        _lastNumberVal = number;
        _result /= number;
    }

    void Multiply(int number)
    {
        _previousResult = _result;
        _lastOperationStatus = "multiply";
        _lastNumberVal = number;
        _result *= number;
    }
    void CancelLastOperation()
    {
        _lastNumberVal = 0;
        _lastOperationStatus = "cancel last operation";
        _result = _previousResult;
    }

    // print result
    void PrintResult()
    {
        std::cout << "Result After " << _lastOperationStatus << " ";
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

    calc1.CancelLastOperation();
    calc1.PrintResult();

    calc1.Add(3);
    calc1.PrintResult();

    // system("pause>0"); // windows dependent
    // std::cin.get();

    return 0;
}