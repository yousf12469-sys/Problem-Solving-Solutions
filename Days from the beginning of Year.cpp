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
    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? ((IsLeapYear) ? 29 : 28) : NumberOfDays[Month - 1];
}
short NumberOfDaysFromBegeningOfTheYear(short day, short Month, short year)
{
    short TotalDays = 0;
    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberOfDaysInMonth(i, year);
    }
    TotalDays += day;
    return TotalDays;
}
short ReadDays()
{
    short day = 0;
    cout << "please enter a days to check? ";
    cin >> day;
    return day;
}
short ReadMonths()
{
    short Month = 0;
    cout << "please enter a Months to check? ";
    cin >> Month;
    return Month;
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
    short day = ReadDays();
    short Month = ReadMonths();
    short year = ReadYear();

    cout << "\n\nNumber of Days from beginning of the Year Is : " 
        << NumberOfDaysFromBegeningOfTheYear(day, Month, year);

    system("pause>0");
    return 0;
}