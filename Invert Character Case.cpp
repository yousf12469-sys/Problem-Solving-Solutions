#include <iostream>
#include <string>
#include <iostream>

using namespace std;

char ReadChar()
{
    char ch1;
    cout << "please enter your char: ";
    cin >> ch1;
    return ch1;
}
char InvertLetterCase(char char1)
{
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

int main()
{
    char ch1 = ReadChar();
    cout << "\nchar after case: \n";
    ch1 = InvertLetterCase(ch1);
    cout << ch1 << endl;

    system("pause>0");
}