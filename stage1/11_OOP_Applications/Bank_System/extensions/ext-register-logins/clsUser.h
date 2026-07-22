#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include "clsDate.h"

class clsUser : public clsPerson
{
private:
    // static inline int _UserId = 100;
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };

    enMode _Mode;
    string _UserName;
    string _UserPassword;
    int _Permissions;

    bool _MarkedForDelete = false;

    // 4 methods for dealing with CSV database files (Write, Read,Delete, Update)

    static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(enMode::UpdateMode, vUserData[0],
                       vUserData[1], vUserData[2], vUserData[3],
                       vUserData[4], vUserData[5], stoi(vUserData[6]));
    }

    static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
    {
        string UserRecord = "";

        // line += to_string(_UserId) + seperator;
        UserRecord += User.FirstName() + Seperator;
        UserRecord += User.LastName() + Seperator;
        UserRecord += User.Email() + Seperator;
        UserRecord += User.Phone() + Seperator;
        UserRecord += User.UserName() + Seperator;
        UserRecord += User._UserPassword + Seperator;
        UserRecord += to_string(User._Permissions);

        return UserRecord;
    }

    static void _SaveUsersDataToFile(vector<clsUser> vUsers)
    {
        std::ofstream Users_Out_CSV_DBFile; // open for overwrite all file content

        Users_Out_CSV_DBFile.open("Users.txt", ios::out);

        string UserRecord;

        if (Users_Out_CSV_DBFile.is_open())
        {
            for (clsUser usr : vUsers)
            {
                // writes only not deleted users
                if (usr._MarkedForDelete == false)
                {
                    UserRecord = _ConvertUserObjectToLine(usr);
                    Users_Out_CSV_DBFile << UserRecord << endl;
                }
            }
            Users_Out_CSV_DBFile.close();
        }
        else
        {
            cout << "user file failed to open\n";
        }
    }

    static vector<clsUser> _LoadUserLinesFromFile()
    {
        ifstream Users_CSV_DBFile("Users.txt"); // open for reading
        vector<clsUser> vUsers;

        if (Users_CSV_DBFile.is_open())
        {
            string line;

            while (getline(Users_CSV_DBFile, line))
            {
                vUsers.push_back(_ConvertLineToUserObject(line));
            }
            Users_CSV_DBFile.close();
        }
        return vUsers;
    }

    // write or saves new current userdata updates to DB csv file
    // changes like calling setUserName by calling UpdateUserName
    void _Update()
    {
        vector<clsUser> _vUsers;
        _vUsers = _LoadUserLinesFromFile();

        for (clsUser &usr : _vUsers)
        {
            // brute force search for current user by user name
            // multiple users with the same user name caused bug
            // no data integrity
            if (usr.UserName() == this->UserName())
            {
                usr = *this;
                break;
            }
        }
        _SaveUsersDataToFile(_vUsers);
    }

    void _AddNew()
    {
        ofstream CSVFileDB("Users.txt", ios::out | ios::app);

        if (CSVFileDB.is_open())
        {
            CSVFileDB << _ConvertUserObjectToLine(*this) << endl;
        }
    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    static string _GetRegisterLoginRecord(clsUser &usr)
    {
        // Date - time, username, password, permissions
        string delimiter = "#//#";
        return clsDate::GetSystemDateTimeToString() + delimiter + usr.UserName() + delimiter + usr.Password() + delimiter + to_string(usr.Permissions());
    }

public:
    clsUser(enMode mode, string first_name,
            string last_name, string email,
            string phone, string user_name,
            string password, int permssions) : clsPerson(first_name, last_name, email, phone)
    {
        // _UserId++;
        _Mode = mode;
        _UserName = user_name;
        _UserPassword = password;
        _Permissions = permssions;
    }

    enum enPermissions
    {
        pFullAccess = -1,
        pListClients = 1,
        pAddNewClient = 2,
        pDeleteClient = 4,
        pUpdateClient = 8,
        pFindClient = 16,
        pTranactions = 32,
        pManageUsers = 64,
        pLoginRegister = 128,
    };

    // read only property
    // int UserId() const
    // {
    //     return _UserId;
    // }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }
    void MarkedForDeleted()
    {
        _MarkedForDelete = true;
    }

    void SetUserName(string user_name)
    {
        _UserName = user_name;
    }
    string UserName() const
    {
        return _UserName;
    }
    void SetPassword(string password)
    {
        _UserPassword = password;
    }
    string Password() const
    {
        return _UserPassword;
    }

    void SetPermissions(int permissions)
    {
        _Permissions = permissions;
    }

    int Permissions()
    {
        return _Permissions;
    }

    static clsUser Find(string user_name)
    {
        // we load all database table records to find a specific
        // imagine you have 10000 user it will very very slow
        vector<clsUser> vUsers;
        vUsers = _LoadUserLinesFromFile();
        for (clsUser &usr : vUsers)
        {
            if (user_name == usr.UserName())
                return usr;
        }
        return _GetEmptyUserObject();
    }

    static clsUser Find(string user_name, string password)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in); // read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLineToUserObject(Line);
                if (User.UserName() == user_name && User.Password() == password)
                {
                    MyFile.close();
                    return User;
                }
            }
            MyFile.close();
        }
        else
        {
            cout << "failed to open Users DB File..\n";
        }
        return _GetEmptyUserObject();
    }

    static bool IsUserExist(string UserName)
    {
        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    enum enSaveResult
    {
        svFailedEmpty = 0,
        svSucceeded = 1,
        svFailedUserExists = 2
    };

    //
    enSaveResult Save()
    {
        switch (this->_Mode)
        {
        case enMode::EmptyMode:
        {
            return enSaveResult::svFailedEmpty;
            break;
        }
        case enMode::UpdateMode:
        {
            _Update();
            return enSaveResult::svSucceeded;
            break;
        }
        case enMode::AddNewMode:
        {
            // this will add new record to file or database
            if (clsUser::IsUserExist(this->UserName()))
            {
                return enSaveResult::svFailedUserExists;
            }
            else
            {
                _AddNew();
                // we have to set the mode to update after adding a new user
                _Mode = enMode::UpdateMode;
                return enSaveResult::svSucceeded;
            }
            break;
        }
        default:
        {
            return enSaveResult::svFailedEmpty;
            break;
        }
        }
    }
    bool Delete(string user_name)
    {
        vector<clsUser> vUsers;
        vUsers = _LoadUserLinesFromFile();
        for (clsUser &usr : vUsers)
        {
            if (user_name == usr.UserName())
            {
                usr.MarkedForDeleted();
                break;
            }
        }
        _SaveUsersDataToFile(vUsers); // to update DB by deleting user that marked for delete

        *this = _GetEmptyUserObject();
        return true;
    }

    static clsUser GetAddNewUserObject(string user_name)
    {
        return clsUser(enMode::AddNewMode, "", "", "", "", user_name, "", 0);
    }

    static vector<clsUser> GetUsersLists()
    {
        return _LoadUserLinesFromFile();
    }
    void RegisterLogin()
    {
        std::ofstream file;
        file.open("RegisterLogins.txt", ios::out | ios::app);

        if (file.is_open())
        {
            file << _GetRegisterLoginRecord(*this) << endl;
        }
        else
        {
            cout << "Can't open register logins file\n";
        }
        file.close();
    }
};
