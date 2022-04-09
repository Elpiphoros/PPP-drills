#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> num = {1, 2, 3, 4, 5};
    vector<int> :: iterator item;
    cout << "Initial Element: ";
    
    for(item = num.begin(); item != num.end(); item++)
    {
        cout << *item << " ";
    }
    
    return 0;
}
