#include <iostream>
#include <string>
using namespace std;

struct sDate
{
    short year;
    short Month;
    short day;
};
bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short NumberOfDaysInMonth(short Month, short year)
{
    if (Month < 1 || Month > 12)
        return 0;
    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[Month - 1];
}
bool IsValidDate(sDate Date)
{
    if (Date.day < 1 || Date.day > 31)
        return false;
    if (Date.Month < 1 || Date.Month > 12)
        return false;
    if (Date.Month = 2)
    {
        if(IsLeapYear(Date.year))
        {
            if (Date.day > 29)
                return false;
        }
        else
        {
            if (Date.day > 28)
                return false;
        }
    }
    short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.year);
    if (Date.day > DaysInMonth)
        return false;
    return true;
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
sDate ReadFullDate()
{
    sDate Date;
    Date.day = ReadDays();
    Date.Month = ReadMonths();
    Date.year = ReadYear();
    return Date;
}
int main()
{
    cout << "\nEnter a Date:\n";
    sDate Date = ReadFullDate();

    if (IsValidDate(Date))
        cout << "\nYes, Date is a validate date.\n";
    else
        cout << "\nNo, Date is not validate date.\n";
    

    system("pause>0");

    return 0;
}