#include <iostream>
#include <string>
using namespace std;

bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
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
