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
sDate DecreaseDateByOneDay(sDate Date)
{
    if (Date.day == 1)
    {
        if (Date.Month == 1)
        {
            Date.day = 31;
            Date.Month = 12;
            Date.year--;
        }
        else
        {
            Date.day = NumberOfDaysInMonth(Date.Month, Date.year);
            Date.Month--;
        }
    }
    else
    {
        Date.day--;
    }
    return Date;
}
/*void SwapDates(sDate& Date1, sDate& Date2)
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


    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);

    }
    return IncludeEndDay ? ++Days  : Days ;
}*/

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
sDate DecreaseDateByXDay(short days, sDate Date)
{
    for (short i = 1; i <= days; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}
sDate DecreaseDateByOneWeak(sDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}
sDate DecreaseDateByXWeaks(short Weaks, sDate Date)
{
    for (int i = 1; i <= Weaks; i++)
    {
        Date = DecreaseDateByOneWeak(Date);
    }
    return Date;
}
sDate DecreaseDateByOneMonth(sDate Date)
{
    if (Date.Month == 1)
    {
        Date.Month = 12;
        Date.year--;
    }
    else
    {
        Date.Month--;
    }

    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.year);
    if (Date.day > NumberOfDaysInCurrentMonth)
    {
        Date.day = NumberOfDaysInCurrentMonth;
    }
    return Date;
}
sDate DecreaseDateByXMonth(short Month, sDate Date)
{
    for (int i = 1; i <= Month; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}
sDate DecreaseDateByOneYear(sDate Date)
{
    Date.year--;
    return Date;
}
sDate DecreaseDateByXYear(short years, sDate Date)
{
    for (int i = 1; i <= years; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}
sDate DecreaseDateByXYearsFaster(short years, sDate Date)
{
    Date.year -= years;
    return Date;
}
sDate DecreaseDateByOneDecade(sDate Date)
{
    Date.year -= 10;
    return Date;
}
sDate DecreaseDateByXDecide(short Decide, sDate Date)
{
    for (int i = 1; i <= Decide * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}
sDate DecreaseDateByXDecideFaster(short Decide, sDate Date)
{
    Date.year -= Decide * 10;
    return Date;
}
sDate DecreaseDateByOneCountry(sDate Date)
{
    Date.year -= 100;
    return Date;
}
sDate DecreaseDateByOneMillennium(sDate Date)
{
    Date.year -= 1000;
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
    cout << "\nDate affter : \n";
    Date1 = DecreaseDateByOneDay(Date1);
    cout << "\n01-Subtracting one day is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    Date1 = DecreaseDateByXDay(10, Date1);
    cout << "\n02-Subtracting 10 day is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    Date1 = DecreaseDateByOneWeak(Date1);
    cout << "\n03-Subtracting one weak is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    Date1 = DecreaseDateByXWeaks(10, Date1);
    cout << "\n04-Subtracting 10 weaks is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    Date1 = DecreaseDateByOneMonth(Date1);
    cout << "\n05-Subtracting one month is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    Date1 = DecreaseDateByXMonth(5, Date1);
    cout << "\n06-Subtracting 5 months is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    Date1 = DecreaseDateByOneYear(Date1);
    cout << "\n07-Subtracting one year is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    Date1 = DecreaseDateByXYear(10, Date1);
    cout << "\n08-Subtracting 10 year is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    Date1 = DecreaseDateByXYearsFaster(10, Date1);
    cout << "\n09-Subtracting 10 year is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    Date1 = DecreaseDateByOneDecade(Date1);
    cout << "\n10-Subtracting one decide is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    Date1 = DecreaseDateByXDecide(10, Date1);
    cout << "\n11-Subtracting 10 decide is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    Date1 = DecreaseDateByXDecideFaster(10, Date1);
    cout << "\n12-Subtracting 10 decide is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    Date1 = DecreaseDateByOneCountry(Date1);
    cout << "\n13-Subtracting one country is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    Date1 = DecreaseDateByOneMillennium(Date1);
    cout << "\n14-Subtracting one millennium is : " << Date1.day << "/" << Date1.Month << "/" << Date1.year;

    system("pause>0");
    return 0;
}
