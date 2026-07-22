#include <iostream>
#include <vector>
#include <functional>

// ======================================
// الـ Subject — هو اللي عنده البيانات
// ======================================
class SpeedSensor
{
private:
    int current_speed = 0;

    // قائمة بكل الـ subscribers
    // كل subscriber هو function هتتنادي لما السرعة تتغير
    std::vector<std::function<void(int)>> observers;

public:
    // اي كود عايز يتعلم عن السرعة بيسجّل نفسه هنا
    void Subscribe(std::function<void(int)> callback)
    {
        observers.push_back(callback);
    }

    // لما السرعة تتغير — بنبلّغ كل اللي سجّلوا نفسهم
    void SetSpeed(int speed)
    {
        current_speed = speed;
        NotifyAll();
    }

private:
    void NotifyAll()
    {
        for (auto &observer : observers)
        {
            observer(current_speed); // Framework بيناديهم — مش هما بينادوه
        }
    }
};

// ======================================
// الـ Observers — هما اللي عايزين يعرفوا
// ======================================
class Dashboard
{
public:
    void OnSpeedChanged(int speed)
    {
        std::cout << "[Dashboard] Speed: " << speed << " km/h\n";
    }
};

class SpeedLimitWarning
{
public:
    void OnSpeedChanged(int speed)
    {
        if (speed > 120)
        {
            std::cout << "[WARNING] Over speed limit!\n";
        }
    }
};

// ======================================
// الـ Main — وصّل كل حاجة ببعض
// ======================================

void callback_dash(int s)
{
    Dashboard dash; // subscriber 1
    dash.OnSpeedChanged(s);
}

int main()
{
    SpeedSensor sensor; // service

    Dashboard dash; // subscriber 1
    SpeedLimitWarning warning;

    std::function<void(int)> dashCallback = callback_dash;

    // std::function<void(int)> dashCallback = [&dash](int s)
    // { dash.OnSpeedChanged(s); };

    // sensor.Subscribe();
    sensor.Subscribe(dashCallback);
    // كل component بيسجّل نفسه
    // sensor.Subscribe(
    //     [&dash](int s)
    //     { dash.OnSpeedChanged(s); });

    sensor.Subscribe([&warning](int s)
                     { warning.OnSpeedChanged(s); });

    // لما السرعة تتغير — الـ sensor ينبّه الكل تلقائي
    sensor.SetSpeed(60);
    // sensor.SetSpeed(100);
    sensor.SetSpeed(150);
    sensor.SetSpeed(160);
    sensor.SetSpeed(130); // هيطلع warning هنا

    return 0;
}