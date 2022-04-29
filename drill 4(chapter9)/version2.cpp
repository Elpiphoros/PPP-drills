#include "../std_lib_facilities.h"

struct Date
{
    int year, month, day;
    Date(int y, int m, int d);  // check for valid date and initialize
                                //A member function with the same name as its class is special. 
                                //It is called a constructor and will be used for initialization(“construction”) of objects of the class!!
    
                                //eg: Date my_birthday; // error: my_birthday not initialized
                                //    Date today {12,24,2007}; // oops! run-time error
                                //    Date last {2000,12,31}; // OK (colloquial style)
				//    Date last(2000,12,31); // OK (old colloquial style)
                                //    Date next = {2014,2,14}; // also OK (slightly verbose)
                                //    Date christmas = Date{1976,12,24}; // also OK (verbose style)
    
    void add_day(int n);        // increase the Date by n days

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
	if (day > 31) 
	{
		month++;
		day -= 31;
		if (month > 12)
		{
			year++;
			month -= 12;
		}
	}
}
       

int main()
try
{   
    Date today {1978, 6, 25};
         cout << "today: " << today.year << "." << today.month << "." << today.day << endl;
    Date tomorrow = today.add_day(1);
         cout << "tomorrow: " << tomorrow.year << "." << tomorrow.month << "." << tomorrow.day << endl;
	
    //invalid date to check
    Date x {-2, 13, 32};
    cout << x.y << "." << x.m << "." << x.d << endl;
     
    return 0;
}
catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
}
