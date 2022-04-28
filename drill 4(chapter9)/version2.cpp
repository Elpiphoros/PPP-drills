#include "../std_lib_facilities.h"

struct Date
{
    int year, month, day;
    Date(int y, int m, int d);
    void add_day(int n);

};

Date::Date(int y, int m, int d)
{
    if (y > 0)
        year = y;
    else
        error("Invalid year");
    if (m > 0 && m < 13)
        month = m;
    else 
        error("Invalid month");
    if (d > 0 && d < 32)
        day = d;
    else 
        error("Invalid day");
}

void Date::add_day(int n)
{
    day += n; 
}
       
/*void f()
{
    Date today3;
         today3.y = 2009
         today3.m = 3
         today3.d = 3
    cout << today << '\n';
    
    init_day(today3, 2009, 3, 3);
     
    Date tomorrow;
         tomorrow.y = today3.y;
         tomorrow.m = today3.m;
         tomorrow.d = today3.d + 1;
    cout << tomorrow << '\n';
    add_day(today3, 1);
}*/
int main()
{
    //Date my_birthday;
    //Date today{12,24,2007};
    
    Date last{2000, 12, 31};
         cout << last.year << "." << last.month << "." << last.day << '\n';
    Date next = {2014, 2, 14};
         cout << next.year << "." << last.month << "." << last.day << '\n';
    Date christmas = Date{1976, 12, 24};   
         cout << christmas.year << "." << christmas.month << "." << christmas.day << '\n';
     
    return 0;
}
