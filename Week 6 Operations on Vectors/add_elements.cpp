#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> num{1, 2, 3, 4, 5};
    
    cout << "Initial Element";
    
    for(const int& i :num)
    {
        cout << i << " ";
    }
    
    //add integer 6 and 7
    num.push_back(6);
    num.push_back(7);
    
    cout << "Update Element";
    
    for(const int& i :num)
    {
        cout << i << " ";
    }
    
    return 0;
}
