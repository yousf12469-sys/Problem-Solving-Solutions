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


/*int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int Days = 0;


    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);

    }
    return IncludeEndDay ? ++Days : Days;
}*/
short DayOfWeekOrder(short Day, short Month, short Year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12 * a) - 2;

    return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
short DayOfWeekOrder(sDate Date)
{
    return DayOfWeekOrder(Date.day, Date.Month, Date.year);
}
string DayShortName(short DayOfWeekOrder)
{
    string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
    return arrDayNames[DayOfWeekOrder];
}
bool IsEndOfWeek(sDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}
bool IsWeekEnd(sDate Date)
{
    short DaysIndex = DayOfWeekOrder(Date);
    return (DaysIndex == 6 || DaysIndex == 5);
}
bool IsBusinessDay(sDate Date)
{
    //short DaysIndex = DayOfWeekOrder(Date);
    //return (DaysIndex >= 0 && DaysIndex <= 4);

    return !IsWeekEnd(Date);
}
/*
short DaysUntilTheEndOfWeek(sDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}
short DaysUntilTheEndOfMonth(sDate Date)
{
    sDate EndOfMonthDate;
    EndOfMonthDate.day = NumberOfDaysInMonth(Date.Month, Date.year);
    EndOfMonthDate.Month = Date.Month;
    EndOfMonthDate.year = Date.year;

    return GetDifferenceInDays(Date, EndOfMonthDate, true);
}
short DaysUntilTheEndOfYear(sDate Date)
{
    sDate EndOfMonthDate;
    EndOfMonthDate.day = 31;
    EndOfMonthDate.Month = 12;
    EndOfMonthDate.year = Date.year;

    return GetDifferenceInDays(Date, EndOfMonthDate, true);
}
*/
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
/*
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
short CalculateVacationDay(sDate DateFrom, sDate DateTo)
{
    short DaysCount = 0;
    while (IsDate1BeforeDate2(DateFrom, DateTo))
    {
        if (IsBusinessDay(DateFrom))
            DaysCount++;
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    return DaysCount;
}

int main()
{
    cout << "\nVacations Starts : \n";
    sDate DateFrom = ReadFullDate();
    
    cout << "\nVacations Ends : \n";
    sDate DateTo = ReadFullDate();


    cout << "\nVaction from : " << DayShortName(DayOfWeekOrder(DateFrom)) << " , " << DateFrom.day << "/" << DateFrom.Month << "/" << DateFrom.year << endl;

    cout << "\nVaction to : " << DayShortName(DayOfWeekOrder(DateTo)) << " , " << DateTo.day << "/" << DateTo.Month << "/" << DateTo.year << endl;


    cout << "\n\nActual Vacations Days is : " << CalculateVacationDay(DateFrom, DateTo);

    system("pause>0");
    return 0;
}
