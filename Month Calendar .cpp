#include <iostream>
#include <string>
using namespace std;

bool IsLeapYear(short year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
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

short NumberOfDaysInMonth(short Month, short year)
{
    if (Month < 1 || Month > 12)
        return 0;
    int NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDays[Month - 1];
}
string MonthShortName(short MonthNumber)
{
    string Months[12] = { "jan", "feb", "mar", "abr",
        "may", "jun", "jul", "aug",
        "sep", "oct", "nov", "dec" };
    return (Months[MonthNumber - 1]);
}
void PrintMonthCalender(short Month, short year)
{
    int NumberOfDays;
    int current = DayOfWeakOrder(1, Month, year);

    NumberOfDays = NumberOfDaysInMonth(Month, year);

    printf("\n_____________________________%s____________________________\n\n", MonthShortName(Month).c_str());

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for(i = 0; i < current; i++)
    {
        printf("     ");
    }
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n_____________________________________________________________\n");
}

int main()
{
    short year = ReadYear();
    short Month = ReadMonth();

    PrintMonthCalender(Month, year);

    system("pause>0");
    return 0;
}