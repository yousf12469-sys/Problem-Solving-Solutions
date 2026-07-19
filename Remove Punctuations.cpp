#include <iostream>
#include <string>
using namespace std;
string RemovePunctuationsFromString(string s1)
{
    string s2 = "";
    for (short i = 0; i < s1.length(); i++)
    {
        if (!ispunct(s1[i]))
        {
            s2 += s1[i];
        }
    }
    return s2;
}
int main()
{
    string s1 = "Welcome to Jordan, Jordan is a nice country; its amazing.";
    cout << "\nOriginal string:\n" << s1;
    cout << "\n\nPauncuations Removed:\n" << RemovePunctuationsFromString(s1);

    system("pause>0");
}