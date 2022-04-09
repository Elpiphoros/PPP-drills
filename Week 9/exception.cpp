#include<iostream>
using namespace std;
double division(double a, double b)
{
    if(b==0)
    throw "divided by 0";
    else 
    return a/b;
}
int main()
{
    double a,b,c;
    char op;
    
    cout << "give 2 number" <<endl;
    cin >> a;
    cin >> b;
    cout << "choose the operator" <<endl;
    cin >> op;
    
    switch(op)
    {
        case '+' : 
            cout << "a+b= " << a+b ; 
            break;
        case '-' : 
            cout << "a-b= " << a-b ; 
            break;
        case '*' : 
            cout << "a*b= " << a*b ; 
            break;
        case '/' : 
            try
                {
                    c = division(a,b);
                    cout << c << endl;
                }
            catch(const char* msg)
                {
                    cerr << msg <<endl;
                }
    }

    return 0;
}
