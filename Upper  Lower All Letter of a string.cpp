#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
    string s1;
    cout << "please enter your string?\n" << endl;
    getline(cin, s1);
    return s1;

}
string UpperFirstLetterOfEachWord(string s1)
{

    for (short i = 0; i < s1.length(); i++)
    {
        s1[i] = toupper(s1[i]);
        
    }
    return s1;
}
string LowerFirstLetterOfEachWord(string s1)
{

    for (short i = 0; i < s1.length(); i++)
    {
        s1[i] = tolower(s1[i]);

    }
    return s1;
}

int main()
{
    string s1 = ReadString();

    cout << "string after upper conversion: \n" << endl;
    s1 = UpperFirstLetterOfEachWord(s1);
    cout << s1 << endl;

    cout << "string after lower conversion: \n" << endl;
    s1 = LowerFirstLetterOfEachWord(s1);
    cout << s1 << endl;
    system("pause>0");
}
