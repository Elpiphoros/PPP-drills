#include "../std_lib_facilities.h"

// simple Date (control access)
//Date should be inaccessible to users except through the public member functions that we supply.
class Date
{
	int year, month, day; // year, month, day
	
	public:
		Date(int y, int m, int d); 	// check for valid date and initialize
		void add_day(int n); 		// increase the Date by n days
		int get_month() { return m; }
		int get_day() { return d; }
		int get_year() { return y; }
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
    cout << "today: " << today.get_year << "." << today.get_month << "." << today.get_day << endl;
	
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << "tomorrow: " << tomorrow.get_year << "." << tomorrow.get_month << "." << tomorrow.get_day << endl;
	
    //invalid date to check
    Date x {-2, 13, 32};
    cout << x.get_year << "." << x.get_month << "." << x.get_day << endl;
     
    return 0;
}
catch (exception& e)
{
    cout << "Error: " << e.what() << endl;
    return 1;
}
