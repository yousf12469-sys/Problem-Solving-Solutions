#include <iostream>
#include <string>
using namespace std;

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
short ReadDay()
{
    short day = 0;
    cout << "please enter a day? ";
    cin >> day;
    return day;
}
short DayOfWeakOrder(short day, short Month, short year)
{
    short a, y, m;
    a = (14 - Month) / 12;
    y = year - a;
    m = Month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}
string DayShortName(short DayOfWeakOrder)
{
    string arrDayNames[] = { "Sun", "mon", "tue", "wed", "thu", "fri", "sat" };
    return arrDayNames[DayOfWeakOrder];
}

int main()
{
    short year = ReadYear();
    short Month = ReadMonth();
    short day = ReadDay();

    short DayOrder = DayOfWeakOrder(day, Month, year);

    cout << "\n\nDate     : " << day << " / " << Month << " / " << year << endl;

    cout << "day order   : " << DayOrder << endl;

    cout << "day name    : " << DayShortName(DayOrder) << endl;
}