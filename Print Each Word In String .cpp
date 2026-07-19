#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
    string s1;
    cout << "please enter your string?\n";
    getline(cin, s1);
    return s1;
}
void PrintEachwordInString(string s1)
{
    string delim = " ";
    cout << "\nYour string words are: \n\n";
    short pos = 0;
    string sWord;

    while ((pos = s1.find(delim)) != std::string::npos)
    {
        sWord = s1.substr(0, pos);
        if (sWord != "")
        {
            cout << sWord << endl;
        }
        s1.erase(0, pos + delim.length());
    }

    if (s1 != "")
    {
        cout << s1 << endl;
    }
}
int main()
{
    PrintEachwordInString(ReadString());
    system("pause>0");
}