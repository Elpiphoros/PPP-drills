#include "../std_lib_facilities.h"

struct Date 
{
    int y; // year
    int m; // month in year
    int d; // day of month
};

// helper functions:
void init_day(Date& dd, int y, int m, int d)
{
    // check that (y,m,d) is a valid date
    // if it is, use it to initialize dd
    if (y > 0)
        dd.y = y;
    else
        error("Invalid year");
    
    if (m > 0 && m < 13)
        dd.m = m;
    else 
        error("Invalid month");
    
    if (d > 0 && d < 32)
        dd.d = d;
    else 
        error("Invalid day");
}

void add_day(Date& date, int n)
{
    // increase dd by n days
    date.d += n;
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
    // a Date variable (a named object)
    Date today; 
    
    // set today to December 24, 2005
    today.y = 2005;
    today.m = 24;
    today.d = 12;
    
    Date x;
         x.y = -1;
         x.m = 13;
         x.d = 32;
    
    Date y;
         y.y = 2000;
         y.m = 2;
         y.d = 29;

    cout << today.y << "." << today.m << "." << today.d << "."<< endl;  
    
    cout << x.y << "." << x.m << "." << x.d << endl;
    
    cout << y.y << "." << y.m << "." << y.d << endl;
    
    Date today2;
    init_day(today2, 2003, 4, 8);
    cout << today2.y << "." << today2.m << "." << today2.d << endl;
     
    add_day(today2, 1);
    cout << today2.y << "." << today2.m << "." << today2.d << endl;
     
return 0;
}
