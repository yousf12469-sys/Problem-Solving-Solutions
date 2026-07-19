#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

vector <string> SplitString(string S9, string Delim)
{
    vector <string> vString;
    short pos = 0;
    string sWord;

    while ((pos = S9.find(Delim)) != std::string::npos)
    {
        sWord = S9.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S9.erase(0, pos + Delim.length());
    }
    if (S9 != "")
    {
        vString.push_back(S9);
    }
    return vString;
}
struct stClinet
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    int CountBalance = 0;
    bool MarkForDelete = false;
};
string ConvertRecordToLine(stClinet Clinet, string Separator = "#//#")
{
    string stClinetRecord = "";
    stClinetRecord += Clinet.AccountNumber + Separator;
    stClinetRecord += Clinet.PinCode + Separator;
    stClinetRecord += Clinet.Name + Separator;
    stClinetRecord += Clinet.Phone + Separator;
    stClinetRecord += to_string(Clinet.CountBalance);

    return stClinetRecord;
}
stClinet CounvertLineToRecord(string Line, string Separator = "#//#")
{
    stClinet Clinet;
    vector<string> vClinetData;

    vClinetData = SplitString(Line, Separator);

    Clinet.AccountNumber = vClinetData[0];
    Clinet.PinCode = vClinetData[1];
    Clinet.Name = vClinetData[2];
    Clinet.Phone = vClinetData[3];
    Clinet.CountBalance = stod(vClinetData[4]);

    return Clinet;
}
void PrintClinetRecord(stClinet Clinet)
{
    cout << "\n\nThe following are the client Delete : \n\n";

    cout << "Account number   :" << Clinet.AccountNumber << endl;
    cout << "pinCode          :" << Clinet.PinCode << endl;
    cout << "Name             :" << Clinet.Name << endl;
    cout << "phone            :" << Clinet.Phone << endl;
    cout << "Account balance  :" << Clinet.CountBalance << endl;

}
const string ClientsFileName = "Clients.text";

vector <stClinet> LoadClientsDataFromFile(string FileName)
{
    vector<stClinet> vClient;
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        stClinet Clinet;

        while (getline(MyFile, Line))
        {
            Clinet = CounvertLineToRecord(Line);
            vClient.push_back(Clinet);
        }
        MyFile.close();
    }
    return vClient;
}
bool FindClientByAccountNumber(string AccountNumber, vector<stClinet> vClients, stClinet& Client)
{
    for (stClinet c : vClients)
    {
        if (c.AccountNumber == AccountNumber)
        {
            Client = c;
            return true;
        }
    }
    return false;
}
string ReadClientAccountNumber()
{
    string AccountNumber = "";
    cout << "please enter Account number? ";
    cin >> AccountNumber;
    return AccountNumber;
}

vector <stClinet> SaveClientsDataToFile(string FileName, vector <stClinet> vClients)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);
    string DataLine;

    if (MyFile.is_open())
    {
        for (stClinet c : vClients)
        {
            if (c.MarkForDelete == false)
            {
                DataLine = ConvertRecordToLine(c);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}
stClinet ChangeClientRecord(string AccountNumber)
{
    stClinet Client;
    Client.AccountNumber = AccountNumber;

    cout << "enter pin code ?";
    getline(cin >> ws, Client.PinCode);

    cout << "enter name ?";
    getline(cin, Client.Name);

    cout << "enter phone ?";
    getline(cin, Client.Phone);

    cout << "enter account balance ?";
    cin >> Client.CountBalance;

    return Client;
}



bool UpdateClientByAccountNumber(string AccountNumber, vector <stClinet>& vClients)
{
    stClinet Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        PrintClinetRecord(Client);

        cout << "\n\nAre you sure you want delete client ? n/y ?";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            for (stClinet& C : vClients)
            {
                if (C.AccountNumber == AccountNumber)
                {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }

            SaveClientsDataToFile(ClientsFileName, vClients);

            // Refresh Clients 
            vClients = LoadClientsDataFromFile(ClientsFileName);

            cout << "\n\n Client Deleted Successfully. \n";
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is NOT Found!\n";

        return false;
    }
}

int main()
{
    vector <stClinet> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
    system("pause>0");
}

