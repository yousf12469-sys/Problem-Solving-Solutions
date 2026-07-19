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
int main()
{
    vector<string> vString = { "mohammed", "faid", "ali", "maher" };
    cout << "\nVector after join: \n";
    cout << JoinString(vString, " ");

    system("pause>0");
}