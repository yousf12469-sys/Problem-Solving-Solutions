#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
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
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.Month < Date2.Month ? true
        : (Date1.Month == Date2.Month ? Date1.day < Date2.day : false)) : false);
}

short NumberOfDaysInMonth(short Month, short year)
{
    if (Month < 1 || Month > 12)
    {
        return 0;
    }
    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return (Month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[Month - 1];
}
bool IsLastDayInMonth(sDate Date)
{
    return(Date.day == NumberOfDaysInMonth(Date.Month, Date.year));
}
bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}
sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.day = 1;
            Date.Month = 1;
            Date.year++;
        }
        else
        {
            Date.day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.day++;
    }
    return Date;
}
void SwapDates(sDate &Date1, sDate &Date2)
{
    sDate TempDate;

    TempDate.year = Date1.year;
    TempDate.Month = Date1.Month;
    TempDate.day = Date1.day;

    Date1.year = Date2.year;
    Date1.Month = Date2.Month;
    Date1.day = Date2.day;

    Date2.year = TempDate.year;
    Date2.Month = TempDate.Month;
    Date2.day = TempDate.day;
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;
    short SwapFlagValue = 1;
    if(! IsDate1BeforeDate2(Date1, Date2))
    {
        SwapDates(Date1, Date2);
        SwapFlagValue = -1;
    }

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);

    }
    return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
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
/*short ReadDaysToAdd()
{
    short Days;
    cout << "\nHow many days to add? ";
    cin >> Days;
    return Days;
}

sDate GetSystemDate()
{
    sDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);

    Date.year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.day = now->tm_mday;

    return Date;
}*/

int main()
{
    sDate Date1 = ReadFullDate();
    cout << "\n\n";
    sDate Date2 = ReadFullDate();

    cout << "\nDifference is : " << GetDifferenceInDays(Date1, Date2) << "Day(s)";

    cout << "\nDifference (including end day) is  : " << GetDifferenceInDays(Date1, Date2, true) << "Day(s)";

    system("pause>0");
    return 0;
}