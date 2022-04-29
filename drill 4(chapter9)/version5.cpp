#include "../std_lib_facilities.h"

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
        Year(int x): y{x} {if (x < min || x > max) throw Invalid{};}
/* 
eg: Date dx1 {Year{1998}, 4, 3}; // error: 2nd argument not a Month
    Date dx2 {Year{1998}, 4, Month::mar}; // error: 2nd argument not a Month
    Date dx2 {4, Month::mar, Year{1998}}; // error: 1st argument not a Year
    Date dx2 {Month::mar, 4, Year{1998}}; // error: 2nd argument not a Month
    Date dx3 {Year{1998}, Month::mar, 30}; // OK
        int year() {return y;}
        void increment() {y++;}
*/
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


/*
//You can define almost all C++ operators for class or enumeration operands. That’s often called operator overloading.
The ? : construct is an “arithmetic if”: m becomes Jan if (m==Dec) and Month(int(m)+1) otherwise.
It is a reasonably elegant way of expressing the fact that months “wrap around” after December.
eg: Month m = Sep;
    ++m; // m becomes Oct
    ++m; // m becomes Nov
    ++m; // m becomes Dec
    ++m; // m becomes Jan (“wrap around”)
    .... ?    .... : .....   similar in C language!!
    
    An overloaded operator must have at least one user-defined type as operand:
eg: int operator+(int,int); // error: you can’t overload built-in +
    Vector operator+(const Vector&, const Vector &); // OK
    Vector operator+=(const Vector&, int); // OK
*/
Month operator++(Month& m)  // prefix increment operator
{
    m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
    return m;
}

ostream& operator<<(ostream& os, Month m) //output operator!!!
{
    return os << months[int(m)];
}

/*
months has been initialized at the beginning so that (for example) months[int(Month::mar)] is
"March"
*/

class Date
{
    int year;
    Month month;
    int day;
    
public:
    class Invalid {};  //user defined data type  Invalid
    Date(int y, Month m, int d): year(y), month(m), day(d) { if (!is_valid()) throw Invalid {}; }  
	
/*  initilize date and check if it's valid through a function
eg: Date dx1 {1998, 4, 3}; // error: 2nd argument not a Month
    Date dx2 {1998, 4, Month::mar}; // error: 2nd argument not a Month
    Date dx2 {4, Month::mar, 1998}; // oops: run-time error: day 1998
    Date dx2 {Month::mar, 4, 1998}; // error: 2nd argument not a Month
*/
	
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
