#include <iostream>
#include <string>
using namespace std;

bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }
    
    short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays [Month - 1];
    
}
short NumberOfHoursInMonth(short Month, short year)
{
    return NumberOfDaysInMonth(Month, year) * 24;
}
int NumberOfMinutesInMonth(short Month, short year)
{
    return NumberOfHoursInMonth(Month, year) * 60;
}
int NumberOfSecondsInMonth(short Month, short year)
{
    return NumberOfMinutesInMonth(Month, year) * 60;
}

short ReadYear()
{
    short year = 0;
    cout << "please enter a year to check? ";
    cin >> year;
    return year;
}
short ReadMonth()
{
    short Month = 0;
    cout << "please enter a month? ";
    cin >> Month;
    return Month;
}


int main()
{
    short year = ReadYear();
    short Month = ReadMonth();

    cout << "\nNumbers of days in month [ " << Month << "] is " << NumberOfDaysInMonth(Month, year);

    cout << "\nNumbers of hours in month [ " << Month << "] is " << NumberOfHoursInMonth(Month, year);

    cout << "\nNumbers of minutes in month [ " << Month << "] is " << NumberOfMinutesInMonth(Month, year);

    cout << "\nNumbers of seconds in Month [ " << Month << "] is " << NumberOfSecondsInMonth(Month, year);

    system("pause>0");
    return 0;

}