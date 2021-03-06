//program to illustrate the working of the classes and objects

#include <iostream>
using namespace std;

//creating a class

class calculation
{
    public:
    int num1;
    int num2;
    
    int sum()
    {
        return num1 + num2;
    }
    int diff()
    {
        return num1 - num2;
    }
    int max()
    {
        return std::max(num1,num2);
        /* orif(num1>num2)
             return num1;
             else
             return num2;*/
    }
};

int main()
{
    //creating objects
    calculation integer;
    
    integer.num1, integer.num2;
    
    cout << "number 1 = ";
    cin >> integer.num1;
    cout << "number 2 = ";
    cin >> integer.num2;
    
    //calling member function
    cout << "sum = " << integer.sum() << endl;
    cout << "difference = " << integer.diff() <<endl;
    cout << "maximal number = " << integer.max() <<endl;
    
    return 0;
}


//another method to input the number

#include <iostream>
#include<cmath>
using namespace std;

//creating a class

class calculation
{
    private:
    int num1;
    int num2;
    
    public:
    void read()
    {
        cout << "number 1 = ";
        cin >> num1;
        cout << "number 2 = ";
        cin >> num2;
    }
    int sum()
    {
        return num1 + num2;
    }
    int diff()
    {
        return num1 - num2;
    }
    int max()
    {
        return std::max(num1,num2);
    }
};

int main()
{
    //creating objects
    calculation integer;
    
    //calling member function
    integer.read();
    
    cout << "sum = " << integer.sum() << endl;
    cout << "difference = " << integer.diff() <<endl;
    cout << "maximal number = " << integer.max() <<endl;
    
    return 0;

}
