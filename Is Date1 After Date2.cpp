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
    return (Date1.year == Date2.year) ? ((Date1.Month == Date2.Month) ? ((Date1.day == Date2.day) ? true : false) : false ) : false;
}
bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}
enum enDateCompare{Before = -1, Equal = 0, After = 1};

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
    cout << "enter Date 1 ? " << endl;
    sDate Date1 = ReadFullDate();

    cout << "\nenter Date 2 ? " << endl;
    sDate Date2 = ReadFullDate();

    cout << "\nCompare Result = " << compareDates(Date1, Date2);

    system("pause>0");

    return 0;
}