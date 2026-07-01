#include <iostream>
#include <string>
using namespace std;

bool IsLeapYear(short year)
{
    if(year % 400 == 0)
    {
        return true;
    }
    else if(year % 100 == 0)
    {
        return false;
    }
    else if(year % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
short ReadYear()
{
    short year = 0;
    cout << "please enter a year to check? ";
    cin >> year;
    return year;
}

int main()
{
    short year = ReadYear();
    if (IsLeapYear(year))
        cout << "yes , year [ " << year << "] is leap year ";
    else
        cout << "no , year [ " << year << "] is not leap year ";

    system("pause>0");
    return 0;
}
