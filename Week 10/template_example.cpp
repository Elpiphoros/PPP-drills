#include<iostream>

using namespace std;

template <class T, class U> 
class constructor
{
    T x;
    U y;
 
    public:
        constructor(T x, U y) 
        { 
            cout << x << " and " << y << endl; 
        }
};

int main()
{   
    constructor<float,int> constructor1 (2.3,1);
    constructor<int, char> constructor2 (2,'a');
    return 0;
}
