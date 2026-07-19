#include <iostream>
#include <string>
using namespace std;

string ReplaceWordInStringBuiltInFunction(string s1, string StringToReplace, string sReplaceTo)
{
    short Pos = s1.find(StringToReplace);
    while (Pos != std::string::npos)
    {
        s1 = s1.replace(Pos, StringToReplace.length(), sReplaceTo);
        Pos = s1.find(StringToReplace);
    }
    return s1;
}
int main()
{
    string s1 = "Welcome to Jordan , Jordan is a nice country";
    string StringToReplace = "Jordan";
    string ReplaceTo = "USA";
    cout << "\nOriginal String\n" << s1;
    cout << "\n\nString after replace:";
    cout << endl << ReplaceWordInStringBuiltInFunction(s1, StringToReplace, ReplaceTo);
    system("pause>0");
}