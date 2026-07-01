#include <iostream>
#include <string>
using namespace std;

string NumberToText(int number)
{
    if(number == 0)
    {
        return "";
    }
    if(number >= 1 && number <= 19)
    {
        string arr[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight",
            "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
            "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
        return arr[number] + " ";
    }
    if(number >= 20 && number <= 99)
    {
        string arr[] = { "" , "" , "Twenty" , "Thirty" , "Forty" , "Fifty" ,
     "Sixty", "Seventy" , "Eighty" , "Ninety" };
        
        return arr[number / 10] + " " + NumberToText(number % 10);
    }
    if(number >= 100 && number <= 199)
    {
        return "one hundred " + NumberToText(number % 100);
    }
    if(number >= 200 && number <= 999)
    {
        return NumberToText(number / 100) + "hundreds " + NumberToText(number % 100);
    }
    if(number >= 1000 && number <= 1999)
    {
        return "one thousand " + NumberToText(number % 1000);
    }
    if(number >= 2000 && number <= 999999)
    {
        return NumberToText(number / 1000) + "thousands " + NumberToText(number % 1000);
    }
    if(number >= 1000000 && number <= 1999999)
    {
        return " one million " + NumberToText(number % 1000000);
    }
    if(number >= 2000000 && number <= 999999999)
    {
        return NumberToText(number / 1000000) + "millios " + NumberToText(number % 1000000);
    }
    if(number >= 1000000000 && number <= 1999999999)
    {
        return "one billion " + NumberToText(number % 1000000000);
    }
    else
    {
        return NumberToText(number / 1000000000) + "billions " + NumberToText(number % 1000000000);
    }
}
int ReadNumber()
{
    int number = 0;
    cout << "please enter number? ";
    cin >> number;
    return number;
}

int main()
{
    int number = ReadNumber();
    cout << NumberToText(number);
    system("pause>0");
    return 0;
}