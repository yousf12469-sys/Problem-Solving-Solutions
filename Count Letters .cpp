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
short CountLetter(string s1, char Letter)
{
    short Counter = 0;

    for (short i = 0; i < s1.length(); i++)
    {
        if (s1[i] == Letter)
            Counter++;
    }
    return Counter;
}
int main()
{
    string s1 = ReadString();
    char ch1 = ReadChar();

    cout << "\Letter \'" << ch1 << "\' count = " << CountLetter(s1, ch1);

    system("pause>0");
}