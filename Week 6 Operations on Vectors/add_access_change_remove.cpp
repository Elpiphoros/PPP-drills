#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> num{1, 2, 3, 4, 5};
    
    cout << "Initial Element: ";
    
    for(const int& i :num)
    {
        cout << i << " ";
    }
    
    //add integer 6 and 7
    num.push_back(6);
    num.push_back(7);
    
    cout << "\nUpdate Element: ";
    
    for(const int& i :num)
    {
        cout << i << " ";
    }
    
    //access the second Element
    
    cout << "\nthe second element is ";
    cout << num.at(1) <<endl;
    
    cout << "the third element is ";
    cout << num.at(2);
    
    //changing the 3rd element to 4
    
    num.at(2) = 4;
    cout << "\nchanging the 3rd Element is ";
    cout << num.at(2);
    
    //remove Last Element
    
    num.pop_back();
    cout << "\nAfter delete the last element: ";
     for(const int& i :num)
    {
        cout << i << " ";
    }
    
    return 0;
}
