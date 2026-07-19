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
char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}
string InvertAllStringLettersCase(string s1)
{
    for (short i = 0; i < s1.length(); i++)
    {
        s1[i] = InvertLetterCase(s1[i]);
    }
    return s1;
}

int main()
{
    string s1 = ReadString();
    cout << "\nstring after InvertAllStringLettersCase: " << endl;
    s1 = InvertAllStringLettersCase(s1);
    cout << s1 << endl;
    system("pause>0");
}