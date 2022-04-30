/*
1. Define a global vector<int> gv; initialize it with ten ints, 1, 2, 4, 8, 16, etc.
2. Define a function f() taking a vector<int> argument.
3. In f():
a. Define a local vector<int> lv with the same number of elements as the argument vector.
b. Copy the values from gv into lv.
c. Print out the elements of lv.
d. Define a local vector<int> lv2; initialize it to be a copy of the argument vector.
e. Print out the elements of lv2.
4. In main():
a. Call f() with gv as its argument.
b. Define a vector<int> vv, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
c. Call f() with vv as its argument.
*/

#include "../std_lib_facilities.h"

vector<int> gv;     //Define a global vector<int> gv; 

void init_gv(vector<int>& v)
{
    for (int i = 0; i<10; ++i)
        v.push_back(pow(2,i));
}

void print_vec(const vector<int>& v)
{
    for (int i = 0; i<v.size(); ++i)
        cout << v[i] << " ";
}

void f(const vector<int>& v)        //Define a function f() taking a vector<int> argument.
{
    vector<int> lv[v.size()];       //Define a local vector<int> lv with the same number of elements as the argument vector.
    
    lv = gv;                        //Copy the values from gv into lv.
    
    print_vec(lv);                  // Print out the elements of lv.
    cout << endl;
    
    vector<int> lv2;            //Define a local vector<int> lv2; initialize it to be a copy of the argument vector.
    lv2 = v;
    print_vec(lv2);                 //Print out the elements of lv2.
    cout << endl;
}

int main()
try
{
    init_gv(gv);        //initialize vector<int> gv with ten ints, 1, 2, 4, 8, 16, etc.
    
    f(gv);              //Call f() with gv as its argument.
    
    vector<int> vv;     //Define a vector<int> vv, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
    vv.push_back(1);
    for (int i = 1; i<10; ++i)
        vv.push_back((i+1)*vv[i-1]);
    
    f(vv);              //Call f() with vv as its argument.
}
catch (exception& e)
{
    cerr << "exception: " << e.what() << endl;
}
catch (...)
{
    cerr << "exception\n";
}
