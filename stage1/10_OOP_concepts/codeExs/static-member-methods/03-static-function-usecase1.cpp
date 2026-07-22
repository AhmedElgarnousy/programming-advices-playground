#include <iostream>

/*
When multiple objects need to share data
(e.g., an application configuration, a shared cache, or global counters),
a static function provides a controlled interface
to access or update that shared state.
*/

class User
{
private:
    static int activeUsers; // Shared across all instances
public:
    User() { activeUsers++; }
    ~User() { activeUsers--; }

    // Static function to access the private static variable
    static int getActiveUsers()
    {
        return activeUsers;
    }
};

// Definition and initialization outside the class
int User::activeUsers = 0;

int main()
{
    User user1, user2, user3;

    User *puser4 = new User;

    std::cout << "current active users: " << user1.getActiveUsers() << "\n";

    std::cout << "delete user4.\n";
    delete puser4;

    std::cout << "current active users: " << user1.getActiveUsers() << "\n";

    return 0;
}