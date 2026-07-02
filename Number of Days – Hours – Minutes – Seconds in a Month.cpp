#include <iostream>
#include <string>
using namespace std;

bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short year)
{
    if(Month < 1 || Month > 12)
    {
        return 0;
    }
    if (Month == 2)
    {
        return IsLeapYear(year) ? 29 : 28;
    }
    short arr31Days[7] = { 1, 3, 5, 7, 8, 10, 12 };

    for (short i = 1; i <= 7; i++)
    {
        if (arr31Days[i - 1] == Month)
            return 31;
    }

    return 30;
}
short NumberOfHoursInYear(short Month, short year)
{
    return NumberOfDaysInMonth(Month, year) * 24;
}
int NumberOfMinutesInYear(short Month, short year)
{
    return NumberOfHoursInYear(Month, year) * 60;
}
int NumberOfSecondsInYear(short Month, short year)
{
    return NumberOfMinutesInYear(Month, year) * 60;
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

    cout << "\nNumbers of hours in month [ " << Month << "] is " << NumberOfHoursInYear(Month, year);

    cout << "\nNumbers of minutes in month [ " << Month << "] is " << NumberOfMinutesInYear(Month, year);

    cout << "\nNumbers of seconds in Month [ " << Month << "] is " << NumberOfSecondsInYear(Month, year);

    system("pause>0");
    return 0;

}