#include <iostream>
#include <string>
using namespace std;

bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInYear(short year)
{
    return IsLeapYear(year) ? 366 : 365;
}
short NumberOfHoursInYear(short year)
{
    return NumberOfDaysInYear(year) * 24;
}
int NumberOfMinutesInYear(short year)
{
    return NumberOfHoursInYear(year) * 60;
}
int NumberOfSecondsInYear(short year)
{
    return NumberOfMinutesInYear(year) * 60;
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

    cout << "\nNumbers of days in year [ " << year << "] is " << NumberOfDaysInYear(year);
    
    cout << "\nNumbers of hours in year [ " << year << "] is " << NumberOfHoursInYear(year);
    
    cout << "\nNumbers of minutes in year [ " << year << "] is " << NumberOfMinutesInYear(year);
   
    cout << "\nNumbers of seconds in year [ " << year << "] is " << NumberOfSecondsInYear(year);

    system("pause>0");
    return 0;

}