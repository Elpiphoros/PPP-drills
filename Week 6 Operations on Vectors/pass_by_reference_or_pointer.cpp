#include<iostream>
#include<vector>

using namespace std;

/*
// pass-by-value (give the function a copy of the value passed)

int f(int x)
{
    x = x+1; // give the local x a new value
    return x;
}
int main()
{
    int xx = 0;
    cout << f(xx) << '\n';     // write: 1
    cout << xx << '\n';     // write: 0; f() doesn’t change xx
    int yy = 7;
    cout << f(yy) << '\n';     // write: 8
    cout << yy << '\n'; // write: 7; f() doesn’t change yy
}
//An argument of a function f() is a local variable in f() that’s initialized each time f() is called.
*/

//passing by pointer
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10, b = 20;
    swap(&a, &b);
    cout << "a: " << a << " " << "b: " << b;
     
    return 0;
}

/*
// passing by reference
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10, b = 20;
    swap(a, b);
    cout << "a: " << a << " " << "b: " << b;
    
    return 0;
}*/

/*
void print(const vector<double>& v)     // pass-by-const-reference
{
    cout << "{ ";
    for (int i = 0; i<v.size(); ++i) 
    {
        cout << v[i];
        if (i!=v.size()–1) cout << ", ";
    }
    cout << " }\n";
}

void f(int x)
{
    vector<double> vd1(10);         // small vector
    vector<double> vd2(1000000);    // large vector
    vector<double> vd3(x);          // vector of some unknown size
                                    // . . . fill vd1, vd2, vd3 with values . . .
    print(vd1);
    print(vd2);
    print(vd3);
}
//The & means “reference” and the const is there to stop print() modifying its argument by accident.
 print() now refers back to the argument through the reference. 
 
 void print(const vector<double>& v)        // pass-by-const-reference
{
    // . . .
    v[i] = 7;       // error: v is a const (is not mutable)
    // . . .
}
 */
