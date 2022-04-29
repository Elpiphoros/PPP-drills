#include "../../std_lib_facilities.h"

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
    jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

/*An enum (an enumeration) is a very simple user-defined type, specifying its set of values (its enumerators) as symbolic constants. For example:
emu class Month
{
    jan = "January", feb = "February", mar = "March",
    apr = "April", may = "May", jun = "June",
    jul = "July", aug = "August", sep = "September",
    oct = "October", nov = "November", dec = "December"
};
The “body” of an enumeration is simply a list of its enumerators. 
The class in enum class means that the enumerators are in the scope of the enumeration. That is, to refer to jan, we have to say Month::jan.
eg: Month m = Month::jan;
    Month m2 = feb;  // error: feb is not in scope
    string n = m;    // error: can’t assign a Month to a string
*/
