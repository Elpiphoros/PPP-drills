/*
1. Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.
2. Define a function f() taking an int array argument and an int argument indicating the number of elements in the array.
3. In f():
    a. Define a local int array la of ten ints.
    b. Copy the values from ga into la.
    c. Print out the elements of la.
    d. Define a pointer p to int and initialize it with an array allocated on the free store with the same number of elements as the argument array.
    e. Copy the values from the argument array into the free-store array.
    f. Print out the elements of the free-store array.
    g. Deallocate the free-store array.
4. In main():
    a. Call f() with ga as its argument.
    b. Define an array aa with ten elements, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
    c. Call f() with aa as its argument.
 */ 
  
#include "../std_lib_facilities.h"

int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };  //Define a global int array ga of ten ints initialized to 1, 2, 4, 8, 16, etc.

void print_ar(const int ai[], int n)
{
    for (int i = 0; i<n; ++i) 
        cout << ai[i] << " ";
}

void f(int ai[], int n) 
{
    int la[10]; // Define a local int array la of ten ints.
    
    for (int i = 0; i<10; ++i) //Copy the values from ga into la through a loop
        la[i] = ga[i];
    
    print_ar(la,10);      //Print out the elements of la.
    cout << endl;
    
    int* p = new int[n];  //Define a pointer p to int and 
                          //initialize it with an array allocated on the free store with the same number of elements as the argument array.
    
    for (int i = 0; i<n; ++i) 
        p[i] = ai[i];   //Copy the values from the argument array into the free-store array.
    print_ar(p,n);      //Print out the elements of the free-store array.
    cout << endl;
    
    delete[] p;         //Deallocate the free-store array.
}

int main()
try
{
    f(ga,10);           //Call f() with ga as its argument.
    
    int aa[10] = { 1 }; //Define an array aa with ten elements, and initialize it with the first ten factorial values (1, 2*1, 3*2*1, 4*3*2*1, etc.).
    for (int i = 1; i<10; ++i) 
        aa[i] = aa[i-1]*(i+1);
    f(aa,10);
}
catch (exception& e)
{
    cerr << "exception: " << e.what() << endl;
}
catch (...) 
{
    cerr << "exception\n";
}
