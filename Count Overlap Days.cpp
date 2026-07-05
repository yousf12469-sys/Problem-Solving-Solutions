#pragma warning(disable : 4996) 
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
struct stPeriod
{
    sDate StartDate;
    sDate EndDate;
};

/*bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return (Date1.year > Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.Month > Date2.Month ? true
        : (Date1.Month == Date2.Month ? Date1.day > Date2.day : false)) : false);
}
*/
bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.Month < Date2.Month ? true
        : (Date1.Month == Date2.Month ? Date1.day < Date2.day : false)) : false);
}
bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return (Date1.year == Date2.year) ? ((Date1.Month == Date2.Month) ? ((Date1.day == Date2.day) ? true : false) : false) : false;
}
bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}
bool IsLeapYeaar(short year)
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
    return (Month == 2) ? (IsLeapYeaar(year) ? 29 : 28) : NumberOfDays[Month - 1];
}
bool IsLastDayInMonth(sDate Date)
{
    return (Date.day == NumberOfDaysInMonth(Date.Month, Date.year));
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
            Date.Month = 1;
            Date.day = 1;
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
void SwapDates(sDate& Date1, sDate& Date2)
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

    if (!IsDate1BeforeDate2(Date1, Date2))
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
int PeriodLengthInDay(stPeriod Period, bool IncludeEndDate = false)
{
    return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
}
enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare compareDates(sDate Date1, sDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    //if (IsDate1AfterDate2(Date1, Date2))
      //  return enDateCompare::After;

    return enDateCompare::After;

}
bool IsDateInPeriod(sDate Date, stPeriod Period)
{
    return !(compareDates(Date, Period.StartDate) == enDateCompare::Before || compareDates(Date, Period.EndDate) == enDateCompare::After);
}
bool IsOverLapPeriod(stPeriod Period1, stPeriod Period2)
{
    if (compareDates(Period2.EndDate, Period1.StartDate) == enDateCompare::Before || compareDates(Period2.StartDate, Period1.EndDate) == enDateCompare::After)
        return false;
    else
        return true;
}
int CountOverlapDays(stPeriod Period1, stPeriod Period2)
{
    int Period1Length = PeriodLengthInDay(Period1, true);
    int Period2Length = PeriodLengthInDay(Period2, true);
    int OverlapDays = 0;

    if (!IsOverLapPeriod(Period1, Period2))
        return 0;

    if (Period1Length < Period2Length)
    {
        while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
        {
            if (IsDateInPeriod(Period1.StartDate, Period2))
                OverlapDays++;
            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        }

    }
    else
    {
        while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
        {
            if (IsDateInPeriod(Period2.StartDate, Period1))
                OverlapDays++;
            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
        }
    }
    return OverlapDays;
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
stPeriod ReadPeriod()
{
    stPeriod Period;

    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();

    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();

    return Period;
}

int main()
{
    cout << "\nEnter Period 1:";
    stPeriod Period1 = ReadPeriod();

    cout << "\nEnter Period 1:";
    stPeriod Period2 = ReadPeriod();

    cout << "\nOverlap Days Count Is: " << CountOverlapDays(Period1, Period2);

    system("pause>0");

    return 0;
}