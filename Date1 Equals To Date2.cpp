#include <iostream>
#include <string>
using namespace std;

struct sDate
{
    short year;
    short Month;
    short day;
};
bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return (Date1.year == Date2.year) ? ((Date1.Month == Date2.Month) ? ((Date1.day == Date2.day) ? true : false) : false) : false;
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
}*/

int main()
{
    sDate Date1 = ReadFullDate();
    cout << endl << endl;
    sDate Date2 = ReadFullDate();

    if (IsDate1EqualDate2(Date1, Date2))
        cout << "\nYes, Date1 is equal Date2.";
    else
        cout << "\nNo, Date1 is NOT equal Date2.";

    system("pause>0");
    return 0;
}