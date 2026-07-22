#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

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

    // For console printing format
    std::string ToString()
    {
        std::ostringstream oss;
        oss << "\nInfo:\n--------------------\n"
            << "ID        : " << ID() << "\n" // Handles int automatically
            << "FirstName : " << FirstName() << "\n"
            << "LastName  : " << LastName() << "\n"
            << "FullName  : " << FullName() << "\n"
            << "Email     : " << Email() << "\n"
            << "Phone     : " << Phone() << "\n"
            << "--------------\n\n";
        return oss.str();
    }

    // for saving in csv file(comma separated values )
    std::string ToStringCSV()
    {
        std::ostringstream oss;
        oss << _ID << "," << _FirstName << "," << _LastName << "," << _email << "," << _phone;

        return oss.str();
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

class clsPersonManager
{
private:
    std::vector<clsPerson> _persons;

public:
    void addPerson(clsPerson &person)
    {
        _persons.push_back(person);
    }

    clsPerson *findPersonById(int id)
    {
        for (auto &person : _persons)
        {

            if (person.ID() == id)
                return &person;
        }
        // Not found, undefined behaviou
        // std::cout << "Persopn ID: " << id << "not exits" << "\n";

        // use pointer and return address of (non-local variable) by
        // auto &person NOT auto person
        return nullptr;
    }

    void SaveToFile(std::string file_name)
    {
        std::ofstream dbFile(file_name);
        for (auto &record : _persons)
            dbFile << record.ToStringCSV();
    }
};

int main()
{
    clsPersonManager perManager;

    clsPerson Person1(10, "ahmed", "kamal", "ahmed97@gmail.com", "01111442559");
    clsPerson Person2(20, "mohamed", "kamal", "mohamed97@gmail.com", "01551332559");
    clsPerson Person3(30, "mostafa", "kamal", "mostafa97@gmail.com", "01001552559");

    perManager.addPerson(Person1);
    perManager.addPerson(Person2);
    perManager.addPerson(Person3);

    std::cout << perManager.findPersonById(20)->ToStringCSV() << "\n";

    perManager.SaveToFile("persons.txt");

    return 0;
}
