#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct sDate
{
    short year;
    short Month;
    short day;
};
vector<string> SplitString(string S1, string Delim)
{
    vector <string> vString;
    short Pos = 0;
    string sWord;

    while((Pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, Pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, Pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }
    return vString;
}
string DateToString(sDate Date)
{
    return to_string(Date.day) + "/" + to_string(Date.Month) + "/" + to_string(Date.year);
}
sDate StringToDate(string DateString)
{
    sDate Date;
    vector<string> vDate;
    vDate = SplitString(DateString, "/");

    Date.day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.year = stoi(vDate[2]);
    return Date;
}
string ReadStringDate(string Message)
{
    string DateString;
    cout << Message;
    getline(cin >> ws, DateString);
    return DateString;
}

int main()
{
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
    sDate Date = StringToDate(DateString);
    
    cout << "\nDay:" << Date.day << endl;
    cout << "\nMonth:" << Date.Month << endl;
    cout << "\nYear:" << Date.year << endl;

    cout << "\nYour Entered " << DateToString(Date) << endl;
}

