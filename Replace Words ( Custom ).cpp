#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
    if (s1 != "")
    {
        vString.push_back(s1);
    }
    return vString;
}
string JoinString(vector<string> vString, string Delim)
{
    string s1;
    for (string& s : vString)
    {
        s1 = s1 + s + Delim;
    }
    return s1.substr(0, s1.length() - Delim.length());
}
string LowerAllString(string s1)
{
    for (short i = 0; i < s1.length(); i++)
    {
        s1[i] = tolower(s1[i]);
    }
    return s1;
}
string ReplaceWordInStringUsingSplit(string s1, string StringToReplace, string sReplaceTo, bool MatchCase = true)
{
    vector<string> vString = SplitString(s1, " ");
    for (string& s : vString)
    {
        if (MatchCase)
        {
            if (s == StringToReplace)
            {
                s = sReplaceTo;
            }
        }
        else
        {
            if (LowerAllString(s) == LowerAllString(StringToReplace))
            {
                s = sReplaceTo;
            }
        }
    }
    return JoinString(vString, " ");
}
int main()
{
    string s1 = "Welcome to Jordan , Jordan is a nice country";
    string StringToReplace = "jordan";
    string ReplaceTo = "USA";

    cout << "\nOriginal string:\n" << s1;

    cout << "\n\nReplace with match case: ";
    cout << endl << ReplaceWordInStringUsingSplit(s1, StringToReplace, ReplaceTo);

    cout << "\n\nReplace with domt match case: ";
    cout << endl << ReplaceWordInStringUsingSplit(s1, StringToReplace, ReplaceTo, false);

    system("pause>0");
}