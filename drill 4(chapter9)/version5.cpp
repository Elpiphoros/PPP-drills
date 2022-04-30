#include "../std_lib_facilities.h"

class Year  // year in [min:max) range
{
    static const int min = 1800;
    static const int max = 2200;
    
    public:
        class Invalid {};
        Year(int x): y{x} {if (x < min || x > max) throw Invalid{};}
        int year() { return y; }
        void increment() { y++; }
	
    private:
        int y;
}

Year operator++(Year& year)
{
    year.increment();
}

ostream& operator<< (ostream& os, Year year)
{
    return os << year.year();
}

const vector<string> months = 
{
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

enum class Month
{
    jan =1 , feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};


Month operator++(Month& m)  // prefix increment operator
{
    m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
    return m;
}

ostream& operator<<(ostream& os, Month m) //output operator!!!
{
    return os << months[int(m)];
}

class Date
{
    int year;
    Month month;
    int day;
    
public:
    class Invalid {};  //user defined data type  Invalid
    Date(int y, Month m, int d): year(y), month(m), day(d) { if (!is_valid()) throw Invalid {}; }  	
    bool is_valid();
    void add_day(int n);
    int get_year() { return year; }
    Month get_month() { return month; }
    int get_day() { return day; }
};

bool Date::is_valid()  // check the year and day is valid or not
{
    if (year < 0 || day < 1 || day > 31)
        return false;
    return true;
}

void Date::add_day(int n)
{
    day += n;
    if (day > 31) 
    {
	++month; // notice here!!if forget, go back and read the example!!
	day -= 31;
	if (month == Month::jan)
	{
		year++;
	}
    }
}

int main()
try
{   
    Date today {1978, Month::jun, 25};
    cout << "today: " << today.get_year() << "." << today.get_month() << "." << today.get_day() << endl;
	
    Date tomorrow = today;
    tomorrow.add_day(1);
    cout << "tomorrow: " << tomorrow.get_year() << "." << tomorrow.get_month() << "." << tomorrow.get_day() << endl;
	
    //invalid date to check
    Date x {-2, Month::aug, 32};
    cout << x.get_year() << "." << x.get_month() << "." << x.get_day() << endl;
     
    return 0;
}
catch (Date::Invalid) //catch the error we defined
{
    cout << "Error: Invalid date\n";
    return 1;
}
catch (exception& e)
{
    cout << "Error: " << e.what() << endl;
    return 1;
}
