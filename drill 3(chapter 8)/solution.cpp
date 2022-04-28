/*  Task:
Write three functions swap_v(int,int), swap_r(int&,int&), and swap_cr(const int&, const int&). 
Each should have the body { int temp; temp = a, a=b; b=temp; } where a and b are the names of the arguments.
Try calling each swap like this

int x = 7;
int y = 9;
swap_?(x,y); // replace ? by v, r, or cr
swap_?(7,9);
const int cx = 7;
const int cy = 9;
swap_?(cx,cy);
swap_?(7.7,9.9);
double dx = 7.7;
double dy = 9.9;
swap_?(dx,dy);

Which functions and calls compiled, and why? 
After each swap that compiled, print the value of the arguments after the call to see if they were actually swapped.
If you are surprised by a result, consult §8swap_cr(const int&, const int&)swap_cr(const int&, const int&).6.
*/

#include "../std_lib_facilities.h"

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_cr(const int& ca, const int& cb)
{
    int a, b;
    a = cb;
    b = ca;
}

int main()
{
    int x = 7;
    int y = 9;
    
    //through variable
    swap_v(x,y);    //x, y cannot exchange their value, only local variable chage their value
    cout << "x = " << x << " y = " << y << endl;
    
    swap_r(x,y);    //x,y successfully exchange
    cout << "x = " << x << " y = " << y << endl;
    
    swap_cr(x,y);   //can exchange since ca cb are const reference,we can adjust the order of return value
    cout << "x = " << x << " y = " << y << endl;
    
    /*
    //pass literal
    swap_v(7,9);    //exchange their value's order in local function. in main function, according to their return order, the value will exchange
    
    swap_r(7,9);    // error!! reference arguments needs variables to refer to
    
    swap_cr(7,9);   //OK! ca cb are const, we can pass literal!
    */
    
    
    const int cx = 7;
    const int cy = 9;
    
    //swap const:  cx, cy cannot exchange their value, because they are const
    swap_v(cx,cy);
    cout << "cx = " << cx << " cy = " << cy << endl;
    
    /*
    swap_r(cx,cy); error: reference refer variable not const
    */
    
    swap_cr(cx,cy);
    cout << "cx = " << cx << " cy = " << cy << endl;
    
    /*
    //pass literal
    swap_v(7.7,9.9);    //can exchange their value, the order will bw 9 7
    
    swap_r(7.7,9.9);    // error!! reference arguments needs variables to refer to
    
    swap_cr(7.7,9.9);   //OK! ca cb are const, we can pass literal!
                           However the double wil become integer, it will be 9 7
    */
    
    double dx = 7.7;
    double dy = 9.9;
    
    //through variable
    swap_v(dx,dy);    //dx, dy cannot exchange their value, only local function chage their value order it will be 9 7
                      //  double become integer!
    cout << "dx = " << dx << " dy = " << dy << endl;    //put double into a function using integer as parameter is not a good idea!!
                                                        // AVOID THAT! 7.7  9.9
    
    /*
    swap_r(dx,dy);    //error!!! dx and dy are double, we need to put integers into the function
    */
    
    swap_cr(dx,dy);   //can exchange since ca cb are const reference,we can adjust the order of return value
    cout << "dx = " << dx << " dy = " << dy << endl;    //7.7  9.9
    
    
    return 0;
}
