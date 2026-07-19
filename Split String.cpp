#include <string>
#include <iostream>
#include <vector>

using namespace std;

string ReadString()
{
    string s1;
    cout << "Please enter your string?\n";
    getline(cin, s1);
    return s1;
}
vector<string> SplitString(string s1, string Delim)
{
    vector<string> vString;
    short Pos = 0;
    string sWord;
    while((Pos = s1.find(Delim)) != std::string::npos)
    {
        sWord = s1.substr(0, Pos);
        if (sWord != "")
        {

            vString.push_back(sWord);
        
        }
        s1.erase(0, Pos + Delim.length());
    }
    if (s1 != "")
    {
        vString.push_back(s1);
    }
    return vString;
}

int main()
{
    vector<string> vString;

    vString = SplitString(ReadString(), " ");

    cout << "\nTokens = " << vString.size() << endl;

    for (string& s : vString)
    {
        cout << s << endl;

    }
    system("pause>0");
}