#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};
sClient ReadNewClient()
{
    sClient Client;
    cout << "Enter account number? ";
    getline(cin, Client.AccountNumber);
    cout << "Enter PinCode?";
    getline(cin, Client.PinCode);
    cout << "Enter name?";
    getline(cin, Client.Name);
    cout << "Enter Phone?";
    getline(cin, Client.Phone);
    cout << "enter account balance";
    cin >> Client.AccountBalance;

    return Client;
}
string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);

    return stClientRecord;
}
int main()
{
    cout << "\nPlease enter client data: \n\n";

    sClient Client;
    Client = ReadNewClient();

    cout << "\n\nClient Record for saving is: \n";
    cout << ConvertRecordToLine(Client);

    system("pause>0");
    return 0;
}