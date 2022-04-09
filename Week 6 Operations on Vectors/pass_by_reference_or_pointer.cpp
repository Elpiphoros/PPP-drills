#include<iostream>
#include<vector>

using namespace std;

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
/*// passing by reference
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
