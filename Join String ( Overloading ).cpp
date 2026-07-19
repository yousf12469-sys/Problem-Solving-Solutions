#include <iostream>
#include <string>
#include <vector>
using namespace std;
string JoinString(vector<string> vString, string Delim)
{
    string s1 = "";
    for (string& s : vString)
    {
        s1 = s1 + s + Delim;
    }
    return s1.substr(0, s1.length() - Delim.length());
}
string JoinString(string arrString[], short Length, string Delim)
{
    string s1 = "";

    for (short i=0; i < Length; i++)
    {
        s1 = s1 + arrString[i] + Delim;
    }
    return s1.substr(0, s1.length() - Delim.length());
}
int main()
{
    vector<string> vString = { "mohammed", "faid", "ali", "maher" };
    string arrString[]= { "mohammed", "faid", "ali", "maher" };
    cout << "\nVector after join: \n";
    cout << JoinString(vString, " ");

    cout << "\nArray after join: \n";
    cout << JoinString(arrString,4, " ");

    system("pause>0");
}