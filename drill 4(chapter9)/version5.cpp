#include "../std_lib_facilities.h"

namespace Chrono
{
	class Year  // year in [min:max) range
	{
    		static constexpr int min = 1800;
    		static constexpr int max = 2200;
    
    		public:
        		class Invalid {};
       			Year(int x): y{x} {if (x < min || x > max) throw Invalid{};}
        		int year() { return y; }
        		void increment() { y++; }
	
    		private:
        		int y;
	};

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
    		jan , feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
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
    		Year year;
    		Month month;
    		int day;
    
		public:
    		class Invalid {};  //user defined data type  Invalid
    		Date(int y, Month m, int d): year(y), month(m), day(d) { if (!is_valid()) throw Invalid {}; }  	
    		bool is_valid();
    		void add_day(int n);
    		Year get_year() { return year; }
    		Month get_month() { return month; }
    		int get_day() { return day; }
	};

	bool Date::is_valid()  // check the year and day is valid or not
	{
    		if (day < 1 || day > 31)
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
				++year;
			}
    		}
	}
} //end namespace

int main()
try
{   
	using namespace Chrono; //notice!!!
	
        Date today {Year{1978}, Month::jun, 25};
        cout << "today: " << today.get_year() << "." << today.get_month() << "." << today.get_day() << endl;
	
        Date tomorrow = today;
        tomorrow.add_day(1);
        cout << "tomorrow: " << tomorrow.get_year() << "." << tomorrow.get_month() << "." << tomorrow.get_day() << endl;
	
	Date my_birthday {Year{2020},Month::dec,31};
        cout << "check Date: " << my_birthday.get_year() << "." << my_birthday.get_month() << "." << my_birthday.get_day() << endl;

        my_birthday.add_day(1);
        cout << "check Date: " << my_birthday.get_year() << "." << my_birthday.get_month() << "." << my_birthday.get_day() << endl;
	
        //invalid date to check
        Date x {Year{-2}, Month::aug, 32};
        cout << x.get_year() << "." << x.get_month() << "." << x.get_day() << endl;
     
        return 0;
}
catch (Chrono::Date::Invalid) //catch the error we defined
{
        cout << "Error: Invalid date\n";
        return 1;
}
catch (Chrono::Year::Invalid) //catch the error we defined
{
        cout << "Error: Invalid date\n";
        return 2;
}
catch (exception& e)
{
        cout << "Error: " << e.what() << endl;
        return 3;
}
