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
short CounterWords(string s1)
{
    string delim = " ";
    short Counter = 0;
    short pos = 0;
    string sWord;

    while ((pos = s1.find(delim)) != std::string::npos)
    {
        sWord = s1.substr(0, pos);
        if (sWord != "")
        {
            Counter++;
        }
        s1.erase(0, pos + delim.length());
    }

    if (s1 != "")
    {
        Counter++;

    }
    return Counter;
}
int main()
{
    string s1 = ReadString();
    cout << "\nThe number of words in your string is: ";
    cout << CounterWords(s1);
    system("pause>0");
}