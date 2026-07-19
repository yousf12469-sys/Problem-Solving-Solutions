#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

const string ClinetsFileName = "Clients.text";

struct stClinet
{
    string AccountNumber = "";
    string PinCode = "";
    string Name = "";
    string Phone = "";
    int AccountBalance = 0;
};
vector <string> SplitString(string S9, string Delim)
{
    vector <string> vString;
    short pos = 0;
    string sWord;

    while((pos = S9.find(Delim)) != std::string::npos)
    {
        sWord = S9.substr(0, pos);

        if(sWord != "")
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
void PrintClientRecord(stClinet Client)
{
    cout << "|  " << left << setw(15) << Client.AccountNumber;
    cout << "|  " << left << setw(10) << Client.PinCode;
    cout << "|  " << left << setw(30) << Client.Name;
    cout << "|  " << left << setw(12) << Client.Phone;
    cout << "|  " << left << setw(12) << Client.AccountBalance;
}
void PrintAllClientsData(vector<stClinet> vClients) 
{
    cout << "\n\t\t\t\t Client list (" << vClients.size() << ") Client(s).";
    cout << "\n____________________________________________________________";
    cout << "________________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code ";
    cout << "| " << left << setw(30) << "Client Name";
    cout << "| " << left << setw(12) << "Phone ";
    cout << "| " << left << setw(12) << "Balance ";

    cout << "\n____________________________________________________________";
    cout << "________________________________________________\n" << endl;

    for (stClinet Client : vClients)
    {
        PrintClientRecord(Client);
        cout << endl;
    }
    cout << "\n_____________________________________________________________________";
    cout << "_________________________________________________________\n" << endl;
}

int main()
{
    vector <stClinet> vClient = LoadClientsDataFromFile(ClinetsFileName);
    PrintAllClientsData(vClient);
    system("pause>0");
}


