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
enum enWhatToCount {SmallLetters = 0, CapitalLetters = 1, All=3};
short CountLetters(string s1, enWhatToCount WhatToCount = enWhatToCount::All)
{

    if (WhatToCount == enWhatToCount::All)
    {
        return s1.length();
    }
    short counter = 0;
    for (short i = 0; i < s1.length(); i++)
    {
        if (WhatToCount == enWhatToCount::CapitalLetters && isupper(s1[i]))
            counter++;
        if (WhatToCount == enWhatToCount::SmallLetters && islower(s1[i]))
            counter++;

    }

    return counter;
}

short CountSmallLetters(string s1)
{
    short counter = 0;
    for (short i = 0; i < s1.length(); i++)
    {
        if (islower(s1[i]))
            counter++;
    }
    return counter;
}
short CountCapitalLetters(string s1)
{
    short counter = 0;
    for (short i = 0; i < s1.length(); i++)
    {
        if (isupper(s1[i]))
            counter++;
    }
    return counter;
}
int main()
{
    string s1 = ReadString();
    cout << "\nstring length = " << s1.length();
    cout << "\ncapital letter count = " << CountCapitalLetters(s1);
    cout << "\nsmall letter count = " << CountSmallLetters(s1);
    cout << endl;
    cout << "\nstring length = " << CountLetters(s1);
    cout << "\ncapital letter count = " << CountLetters(s1, enWhatToCount::CapitalLetters);
    cout << "\nsmall letter count = " << CountLetters(s1, enWhatToCount::SmallLetters);
}