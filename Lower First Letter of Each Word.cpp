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
string LowerFirstLetterOfEachWord(string s1)
{
    bool isFirstLetter = true;

    cout << "\nFirst letter of this string: \n";

    for (short i = 0; i < s1.length(); i++)
    {
        if (s1[i] != ' ' && isFirstLetter)
        {
            s1[i] = tolower(s1[i]);
        }
        isFirstLetter = (s1[i] == ' ' ? true : false);
    }
    return s1;
}

int main()
{
    string s1 = ReadString();
    cout << "string after conversion: \n";
    s1 = LowerFirstLetterOfEachWord(s1);
    cout << s1 << endl;

    system("pause>0");
}
