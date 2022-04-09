#include <iostream>

using namespace std;

int main()
{   
    int *p = new(nothrow) int;
    
    if(!p)
    {
        cout << "failed allocate memory " << endl;
        return 0;
    }
    
    *p = 100;
    cout << "value at allocated memory = " << *p;
    
    delete p;
    return 0;
}


#include <iostream>

using namespace std;

int main()
{   
    int *p = new(nothrow) int[10];
    
    if(!p)
    {
        cout << "failed allocate memory " << endl;
        return 0;
    }
    
    for(int i=0;i<10;i++)
    {
        p[i] = i;
        cout << p[i] << " ";
    }
    
    delete [] p;
    return 0;
}

#include <iostream>

using namespace std;

class test
{
    public:
    test()
    {
        cout << "constructor " << endl;
    }
    
    ~test()
    {
        cout << "destructor " <<endl;
    }
};

int main()
{   
    test sample;
    test *t = new test[2];
    cout << sizeof(sample) <<endl;
    delete []t;
    return 0;
}

#include <iostream>

using namespace std;

class rectangle
{
    public:
    int length;
    int breadth;
    double height;
    
    rectangle()
    {
        cout << "constructor " <<endl;
    }
    
    ~rectangle()
    {
        cout << "destructor " <<endl;
    }
};

int main()
{   
    rectangle object1;
    rectangle *r = new rectangle[2];
    cout << sizeof(object1) <<endl;
    delete []r;
    return 0;
}
