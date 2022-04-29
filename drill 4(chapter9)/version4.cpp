#include "../../std_lib_facilities.h"

class Year  // year in [min:max) range
{
/*
Note the use of "static const" in the definitions of min and max. This is the way we define symbolic constants of integer types within classes.
For a class member, we use static to make sure that there is just one copy of the value in the program, rather than one per object of the class.
In this case, because the initializer is a constant expression, we could have used constexpr instead of const.
*/
    static const int min = 1800;
    static const int max = 2200;
    
    public:
        class Invalid {};
        Year(int x): y{x} {if (x < min || x >= max) throw Invalid{};}
        int year() {return y;}
        void increment() {y++;}
    
    private:
        int y;
    
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

/*An enum (an enumeration) is a very simple user-defined type, specifying its set of values (its enumerators) as symbolic constants. For example:
emu class Month
{
    Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};
The “body” of an enumeration is simply a list of its enumerators. 
The class in enum class means that the enumerators are in the scope of the enumeration. That is, to refer to jan, we have to say Month::jan.
eg: Month m = Month::jan;
    Month m2 = feb;  // error: feb is not in scope
    string n = m;    // error: can’t assign a Month to a string
    
enum Month  // note: no “class”!!!
{
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};
    Month m = feb; // OK: feb in scope!!!
    Month m2 = Month::feb; // also OK
    m = 7; // error: can’t assign an int to a Month
    int n = m; // OK: we can assign a Month to an int
    
    “plain” enums are less strict than enum classes!!
*/

class Date
{
    int year;
    Month month;
    int day;
    
public:
    class Invalid {};
    Date(int y, Month m, int d): year(y), month(m), day(d) { if (!is_valid()) throw Invalid {}; }
    bool is_valid();
    void add_day(int n);
    int get_year() { return year; }
    Month get_month() { return month; }
	int get_day(){ return day; }
};

bool Date::is_valid()
{
    if (year < 0 || day < 1 || day > 31)
        return false;
    return true;
}
