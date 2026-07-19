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
bool IsVowel(char ch1)
{
    ch1 = tolower(ch1);
    return ((ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1 == 'u'));
}
short CountVowels(string s1)
{
    short Counter = 0;

    for (short i = 0; i < s1.length(); i++)
    {
        if (IsVowel(s1[i]))
            Counter++;
    }

    return Counter;
}
int main()
{
    string s1 = ReadString();
    cout << "\nNumber of vowels is: " << CountVowels(s1);

    system("pause>0");
}