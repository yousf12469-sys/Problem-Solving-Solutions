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

    while ((Pos = S1.find(Delim)) != std::string::npos)
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
string ReplaceWordInString(string S1, string StringToReplace, string sReplaceTo)
{
    short Pos = S1.find(StringToReplace);
    while (Pos != std::string::npos)
    {
        S1 = S1.replace(Pos, StringToReplace.length(), sReplaceTo);
        Pos = S1.find(StringToReplace);
    }
    return S1;
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
string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormatedDateString = "";
    FormatedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.day));
    FormatedDateString = ReplaceWordInString(FormatedDateString, "mm", to_string(Date.Month));
    FormatedDateString = ReplaceWordInString(FormatedDateString, "yyyy", to_string(Date.year));
    return FormatedDateString;
}

int main()
{
    string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy? ");
    sDate Date = StringToDate(DateString);

    cout << "\n" << FormateDate(Date)<< endl;
    cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

    system("pause>0");
    return 0;

}

