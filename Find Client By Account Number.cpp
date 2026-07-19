#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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
    int AccountBalance = 0;
};

stClinet CounvertLineToRecord(string Line, string Separator = "#//#")
{
    stClinet Clinet;
    vector <string> vClinetData;
    vClinetData = SplitString(Line, Separator);

    Clinet.AccountNumber = vClinetData[0];
    Clinet.PinCode = vClinetData[1];
    Clinet.Name = vClinetData[2];
    Clinet.Phone = vClinetData[3];
    Clinet.AccountBalance = stod(vClinetData[4]);

    return Clinet;
}

void PrintClientRecord(stClinet Client)
{
    cout << "Account Number " << Client.AccountNumber << endl;
    cout << "Pin Code       " << Client.PinCode << endl;
    cout << "Client Name    " << Client.Name << endl;
    cout << "phone          " << Client.Phone << endl;
    cout << "Balance        " << Client.AccountBalance << endl;
}

vector <stClinet> LoadClientsDataFromFile(string FileName)
{
    vector <stClinet> vClient;
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

const string ClinetsFileName = "Clients.text";

bool FindClientByAccountNumber(string AccountNumber, stClinet& Client)
{
    vector <stClinet> vClients = LoadClientsDataFromFile(ClinetsFileName);

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
    cout << "\nPlease enter Account number? ";
    cin >> AccountNumber;
    return AccountNumber;
}

int main()
{
    stClinet Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, Client))
    {
        PrintClientRecord(Client);
    }
    else
    {
        cout << "\nClient with Account Number ( " << AccountNumber << ") is NOT Found!\n";
        system("pause>0");
    }
}

