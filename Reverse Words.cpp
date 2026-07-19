#include <iostream>
#include <string>
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
string ReverseWordsInString(string s1)
{
	vector<string> vString;
	string s2 = "";
	vString = SplitString(s1, " ");

	vector<string>::iterator iter = vString.end();

	while (iter != vString.begin())
	{
		--iter;

		s2 += *iter + " ";
	}
	s2 = s2.substr(0, s2.length() - 1);
	return s2;
}
int main()
{
	string s1 = ReadString();
	cout << "\n\nString after reversing words:";
	cout << endl << ReverseWordsInString(s1);

	system("pause>0");
}