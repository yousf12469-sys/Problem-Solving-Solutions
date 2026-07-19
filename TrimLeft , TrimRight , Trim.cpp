#include <iostream>
#include <string>

using namespace std;
string TrimLeft(string s1)
{
    for (short i = 0; i < s1.length(); i++)
    {
        if (s1[i] != ' ')
        {
            return s1.substr(i, s1.length() - i);
        }
    }
    return "";
}
string TrimRight(string s1)
{
    for (short i = s1.length() - 1; i >= 0; i--)
    {
        if (s1[i] != ' ')
        {
            return s1.substr(0, i + 1);
        }
    }
    return "";
}

string Trim(string s1)
{
    return (TrimLeft(TrimRight(s1)));
}
int main()
{
    string s1 = "      youssef mohammed      ";
    cout << "\nString       = " << s1;
    cout << "\n\nTrim Left = " << TrimLeft(s1);
    cout << "\n\nTrim Right = " << TrimRight(s1);
    cout << "\nTrim         = " << Trim(s1);

    system("pause>0");
}