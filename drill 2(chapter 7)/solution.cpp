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

#include "std_lib_facilities.h"

class Token
{
	char kind;
	double value;
	string name;
	// three constructors
	Token(char ch) :kind(ch), value(0) {}
	Token(char ch, double val) :kind(ch), value(val) {}
};

class Token_stream
{
	public:
		Token_stream() :full(0), buffer(0) {}
		Token get();
		void unget(Token t);
		void ignore(char); // discard characters up to and including a c
	private:
		bool full;
		Token buffer;
};

void Token_stream::unget(Token t)
{
	if(full)
		error("Token_stream buffer is full");
	buffer = t;
	full = true;
}

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';

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
			cin.unget();
			double val;
			cin >> val;
			return Token(number, val);
		}
		default:
			if (isalpha(ch)) // isalpha(ch). This call answers the question “Is ch a letter?”
			{
				string s;
				s += ch;
				while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) 
					s += ch;
				cin.unget();
				if (s == let) 
					return Token(let);
				if (s == quit) 
					return Token(name);
				return Token(name, s);
			}
			error("Bad token");
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
		if (ch == c) return;
}

class Variable
{
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) {}
};

vector<Variable> names;

double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s)
			return names[i].value;
		error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) 
		{
			names[i].value = d;
			return;
		}
		error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) 
			return true;
		return false;
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
		case name:
			return get_value(t.name);
		default:
			error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) 
	{
		Token t = ts.get();
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
				ts.unget(t);
				return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) 
	{
		Token t = ts.get();
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
				ts.unget(t);
				return left;
		}
	}
}

double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') 
		error("name expected in declaration");
	
	string name = t.name;
	if (is_declared(name))
		error(name, " declared twice");
	
	Token t2 = ts.get();
	if (t2.kind != '=') 
		error("= missing in declaration of ", name);
	
	double d = expression();
	names.push_back(Variable(name, d));
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
			ts.unget(t);
			return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

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
			ts.unget(t);
			cout << result << statement() << endl;
		}
		catch (runtime_error& e) 
		{
			cerr << e.what() << endl;
			clean_up_mess();
		}
}

int main()
try
{
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
