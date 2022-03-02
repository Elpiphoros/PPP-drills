//program to illustrate the working of the classes and objects

#include <iostream>
using namespace std;

//creating a class

class shape
{
    public:
    double length;
    double breadth;
    double height;
    
    double cal_area()
    {
        return length * breadth;
    }
    double cal_volume()
    {
        return length * breadth * height;
    }
};

int main()
{
    //creating objects
    shape rectangle;
    
    rectangle.length = 12.2;
    rectangle.breadth = 15;
    rectangle.height = 10;
    /*or using another way to initialization:
    shape rectangle{12.2,15,10};
    
    //calling member function
    cout << "Area of Rectangle = " << rectangle.cal_area() << endl;
    cout << "volume of Rectangle = " << rectangle.cal_volume() <<endl;
    
    return 0;
}
