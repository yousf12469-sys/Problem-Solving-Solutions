#include <iostream>
#include <string>

using namespace std;

char ReadChar()
{
    char ch1;
    cout << "please enter your character?\n";
    cin >> ch1;

    return ch1;
}
bool IsVowel(char ch1)
{
    ch1 = tolower(ch1);
    return ((ch1 == 'a') || (ch1 == 'e') || (ch1 == 'i') || (ch1 == 'o') || (ch1 == 'u'));
}
int main()
{
    char ch1 = ReadChar();

    if (IsVowel(ch1))
        cout << "\nYes Letter \'" << ch1 << "\' is vowel";
    else
        cout << "\nNo letter \'" << ch1 << "\' is not vowel";
}