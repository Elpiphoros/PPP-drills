/*  Task:
    1. Add a predefined name k meaning 1000.
    2. Give the user a square root function sqrt(), for example, sqrt(2+6.7). Naturally, the value of sqrt(x) is the square root
       of x; for example, sqrt(9) is 3. Use the standard library sqrt() function that is available through the header
       std_lib_facilities.h. Remember to update the comments, including the grammar.
    3. Catch attempts to take the square root of a negative number and print an appropriate error message.
    4. Allow the user to use pow(x,i) to mean “Multiply x with itself i times”; for example, pow(2.5,3) is 2.5*2.5*2.5.
       Require i to be an integer using the technique we used for %.
    5. Change the “declaration keyword” from let to #.
    6. Change the “quit keyword” from quit to exit. That will involve defining a string for quit just as we did for let in§7.8.2.
*/

#include "../../std_lib_facilities.h"

//symblic constants
const char let = 'L';
const char quit = 'q';
const char print = ';';
const char number = '8';
const char name = 'a';
const string declkey = "let";
const string prompt = "> ";
const string result = "= ";

class Variable
{
	public:
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) {}
};

vector<Variable> var_table;

//inpute the name of variable and get its value
double get_value(string s)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s)
			return var_table[i].value;
	error("get: undefined name ", s);
	return -1;
}

//give value to variable
void set_value(string s, double d)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) 
		{
			var_table[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

//does the variable name exist?
bool is_declared(string s)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) 
			return true;
		return false;
}

//if the variable doesn't exist, add the new variable to var_table
double define_name (string var, double val)
{
	if(is_declared(var))
		error(var, "declared twice");
	var_table.push_back(Variable{var,val});
	return val;
}

class Token
{	
	public:
	char kind;
	double value;
	string name;
	// three constructors
	Token() : kind(0) {}
	Token(char ch) :kind(ch), value(0) {}
	Token(char ch, double val) :kind(ch), value(val) {}
	Token(char ch, string n) : kind(ch), name(n) {}
};

class Token_stream
{
	public:
		Token_stream();
		void putback(Token t);
		Token get();
		void ignore(char c); // discard characters up to and including a c
	private:
		bool full;
		Token buffer;
};

Token_stream::Token_stream() :full(false), buffer(0) {}

void Token_stream::putback(Token t)
{
	if(full)
		error("Token_stream buffer is full");
	buffer = t;
	full = true;
}

Token Token_stream::get()
{
	if (full) 
	{ 
		full = false; 
	 	return buffer;
	}
	
	char ch;
	cin >> ch;
	
	switch (ch)
	{
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case ';':
		case '=':
			return Token(ch);
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{	
			cin.putback(ch);
			double val;
			cin >> val;
			return Token(number, val);
		}
		default:
		{
			if (isalpha(ch)) // isalpha(ch). This call answers the question “Is ch a letter?”
			{
				string s;
				s += ch;
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) 
					s += ch;
				cin.putback(ch);
				if (s == declkey) 
					return Token{let};
				else if (is_declared(s)) 
					return Token(number, get_value(s));
				return Token{name, s};
			}
			error("Bad token");
		}
		return 0;
	}
}

void Token_stream::ignore(char c) // c represents the kind of Token
{
	// first look in buffer:
	if (full && c == buffer.kind) 
	{
		full = false;
		return;
	}
	
	full = false;
	
	// now search input:
	char ch = 0;
	while (cin >> ch)
		if (ch == c) 
			return;
}


Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind)
	{
		case '(':
		{	
			double d = expression();
			t = ts.get();
			if (t.kind != ')')
				error("'(' expected");
		}
		case '-':
			return -primary();
		case number:
			return t.value;
		default:
			error("primary expected");
	}
	return -1;
}

double term()
{
	double left = primary();
	Token t = ts.get();
	while (true) 
	{
		switch (t.kind)
		{
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{	
				double d = primary();
				if (d == 0) error("divide by zero");
					left /= d;
					t = ts.get();
					break;
			}
			default:
				ts.putback(t);
				return left;
		}
	}
}

double expression()
{
	double left = term();
	Token t = ts.get();
	while (true) 
	{
		switch (t.kind) 
		{
			case '+':
				left += term();
				t = ts.get();
				break;
			case '-':
				left -= term();
				t = ts.get();
				break;
			default:
				ts.putback(t);
				return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != name) 
		error("name expected in declaration");
	
	string var_name = t.name;
	
	Token t2 = ts.get();
	if (t2.kind != '=') 
		error("= missing in declaration of ", name);
	
	double d = expression();
	define_name(var_name, d);
	return d;
}

double statement()
{
	Token t = ts.get();
	switch (t.kind)
	{
		case let:
			return declaration();
		default:
			ts.putback(t);
			return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

void calculate()
{
	while (cin) 
		try
		{
			cout << prompt;
			Token t = ts.get();
			while (t.kind == print) // first discard all “prints”
				t = ts.get();
			if (t.kind == quit) 
				return;
			ts.putback(t);
			cout << result << statement() << endl;
		}
		catch (exception& e) 
		{
			cerr << e.what() << endl;
			clean_up_mess();
		}
}

int main()
try
{
	define_name("k", 1000);
	calculate();
	return 0;
}
catch (exception& e)
{
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...)
{
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}
