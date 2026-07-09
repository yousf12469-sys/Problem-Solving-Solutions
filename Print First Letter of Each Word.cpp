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
void PrintfirstLetterOfEachWord(string s1)
{
    bool isFirstLetter = true;

    cout << "\nFirst letter of this string: \n";

    for (short i = 0; i < s1.length(); i++)
    {
        if (s1[i] != ' ' && isFirstLetter)
        {
            cout << s1[i] << endl;
        }
        isFirstLetter = (s1[i] == ' ' ? true : false);
    }
}

int main()
{
    PrintfirstLetterOfEachWord(ReadString());

    system("pause>0");
}
