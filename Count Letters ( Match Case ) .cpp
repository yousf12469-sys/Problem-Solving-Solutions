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
char ReadChar()
{
    char ch1;
    cout << "please enter your character?\n";
    cin >> ch1;

    return ch1;
}
char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}
short CountLetter(string s1, char Letter, bool MatchCase = true)
{
    short Counter = 0;

    for (short i = 0; i < s1.length(); i++)
    {
        if (MatchCase)
        {
            if (s1[i] == Letter)
                Counter++;
        }
        else
        {
            if (tolower(s1[i]) == tolower(Letter))
                Counter++;
        }
        
    }
    return Counter;
}
int main()
{
    string s1 = ReadString();
    char ch1 = ReadChar();

    cout << "\Letter \'" << ch1 << "\' count = " << CountLetter(s1, ch1);
    cout << "\Letter \'" << ch1 << "\'";

    cout << "or \'" << InvertLetterCase(ch1) << "\'";
    cout << "count = " << CountLetter(s1, ch1, false);
    system("pause>0");
}