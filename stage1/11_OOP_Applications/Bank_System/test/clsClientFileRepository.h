
#pragma once
#include "clsBankClient.h"
#include "IClientRespository.h"

class clsClientFileRespository
    : public IClientRepository
{

private:
    enum enMode
    {
        EmptyMode = 0,
        UpdateMode = 1,
        AddNewMode = 2
    };
    // guarantees that no object data modification as the method static (no this pointer)
    clsBankClient _ConvertLineToClientObject(string line, string seperator = "#//#", )
    {
        vector<string> vClientDate;
        vClientDate = clsString::Split(line, seperator);

        return clsBankClient(clsClientFileRespository::enMode::UpdateMode, vClientDate[0],
                             vClientDate[1], vClientDate[2], vClientDate[3], vClientDate[4],
                             vClientDate[5], stof(vClientDate[6]));
    }
    static string _ConvertClientObjectToLine(clsBankClient client, string separator = "#//#")
    {
        string clientObjRecord = "";
        clientObjRecord += client.FirstName() + separator;
        clientObjRecord += client.LastName() + separator;
        clientObjRecord += client.Email() + separator;
        clientObjRecord += client.Phone() + separator;
        clientObjRecord += client.AccountNumber() + separator;
        clientObjRecord += client.PinCode() + separator;
        clientObjRecord += to_string(client.AccountBalanace());

        return clientObjRecord;
    }

public:
    vector<clsBankClient> LoadDB()
    {
        vector<clsBankClient> vClients;
        fstream clientsFileDB;
        clientsFileDB.open("Clients.txt", ios::in); // read mode

        if (clientsFileDB.is_open())
        {
            string line;
            while (getline(clientsFileDB, line))
            {
                clsBankClient db_client = _ConvertLineToClientObject(line);
                vClients.push_back(db_client);
            }
            clientsFileDB.close();
        }
        else
        {
            std::cout << "Failed To Open Clients Database!\n";
        }
        return vClients;
    }

    // update database
    void SaveDB(vector<clsBankClient> vClients)
    {
        fstream clientsFileDB;
        string csv_data_line;
        clientsFileDB.open("Clients.txt", ios::out); // overwrite
        if (clientsFileDB.is_open())
        {
            for (clsBankClient C : vClients)
            {
                if (C.MarkedAsDelete() == false)
                {
                    // we write only records that are not marked for delete
                    csv_data_line = _ConvertClientObjectToLine(C);
                    clientsFileDB << csv_data_line << endl;
                }
            }
            clientsFileDB.close();
        }
        else
        {
            std::cout << "Failed To Open Clients CSV DataBase\n";
        }
    }
};