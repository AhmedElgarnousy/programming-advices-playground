#include <iostream>
#include <string>

/**
 * practical API design choice.
 * When designing classes in C++,
 * providing a serialization or string representation methods
 * makes debugging, logging, and data transfer much easier
 */

class clsPerson
{
private:
    int _ID;
    std::string _FirstName;
    std::string _LastName;
    std::string _email;
    std::string _phone;

public:
    clsPerson(int id, const std::string &first_name, const std::string &last_name, const std::string &email, const std::string &phone)
    {
        _ID = id;
        SetFirstName(first_name);
        SetLastName(last_name);
        SetEmail(email);
        SetPhone(phone);
    }

    // Properties (Read-Only ID)
    int ID() const { return _ID; }

    void SetFirstName(const std::string &first_name) { _FirstName = first_name; }
    std::string FirstName() const { return _FirstName; }

    void SetLastName(const std::string &last_name) { _LastName = last_name; }
    std::string LastName() const { return _LastName; }

    std::string FullName() const { return _FirstName + " " + _LastName; }

    void SetEmail(const std::string &email) { _email = email; }
    std::string Email() const { return _email; }

    void SetPhone(const std::string &phone) { _phone = phone; }
    std::string Phone() const { return _phone; }

    // Human-readable text format
    std::string ToString() const
    {
        return "Info:\n--------------------\n"
               "ID        : " +
               std::to_string(ID()) + "\n"
                                      "FirstName : " +
               FirstName() + "\n"
                             "LastName  : " +
               LastName() + "\n"
                            "FullName  : " +
               FullName() + "\n"
                            "Email     : " +
               Email() + "\n"
                         "Phone     : " +
               Phone() + "\n"
                         "--------------------";
    }

    // Machine-readable JSON format (Zero-dependency implementation)
    std::string ToJson() const
    {
        return "{\n"
               "  \"id\": " +
               std::to_string(ID()) + ",\n"
                                      "  \"firstName\": \"" +
               FirstName() + "\",\n"
                             "  \"lastName\": \"" +
               LastName() + "\",\n"
                            "  \"fullName\": \"" +
               FullName() + "\",\n"
                            "  \"email\": \"" +
               Email() + "\",\n"
                         "  \"phone\": \"" +
               Phone() + "\"\n"
                         "}";
    }

    // Business Logic Simulations
    void SendEmail(const std::string &subject, const std::string &body) const
    {
        std::cout << "The following message sent successfully to email: " << Email() << "\n";
        std::cout << "subject: " << subject << "\n";
        std::cout << "body: " << body << "\n\n";
    }

    void SendSMS(const std::string &message) const
    {
        std::cout << "The following SMS sent successfully to phone: " << Phone() << "\n";
        std::cout << "message: " << message << "\n\n";
    }
};

int main()
{
    clsPerson Person1(10, "ahmed", "kamal", "ahmed97@gmail.com", "01551442559");

    // 1. Display text representation
    std::cout << "--- ToString Output ---\n";
    std::cout << Person1.ToString() << "\n\n";

    // 2. Display JSON representation (perfect for API payloads)
    std::cout << "--- ToJson Output ---\n";
    std::cout << Person1.ToJson() << "\n\n";

    // 3. Run actions
    Person1.SendEmail("Hi", "how are you ?");
    Person1.SendSMS("how are you ?");

    return 0;
}
