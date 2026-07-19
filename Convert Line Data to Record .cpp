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
vector<string> SplitString(string s1, string Delim)
{
    vector<string> vString;
    short Pos = 0;
    string sWord;

    while ((Pos = s1.find(Delim)) != std::string::npos)
    {
        sWord = s1.substr(0, Pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        s1.erase(0, Pos + Delim.length());
    }
    if (s1 != "");
    {
        vString.push_back(s1);
    }
    return vString;
}
sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
{
    sClient Client;
    vector<string> vClientData;
    vClientData = SplitString(Line, Seperator);

    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]);

    return Client;
}
void PrintClientRecord(sClient Client)
{
    cout << "\n\nThe following is the extracted client record:\n";
    cout << "\nAccount number: " << Client.AccountNumber;
    cout << "\nPin code      : " << Client.PinCode;
    cout << "\nName          : " << Client.Name;
    cout << "\nphone         : " << Client.Phone;
    cout << "\nAccount balance: " << Client.AccountBalance;
}
int main()
{
    string stLine = "A150#//#1234#//#mohammed#//#03794856876#//#527.000000";
    cout << "\nLine record is: \n";
    cout << stLine;
    sClient Client = ConvertLineToRecord(stLine);
    PrintClientRecord(Client);
    system("pause>0");
    return 0;
}