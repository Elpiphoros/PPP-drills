#include<iostream>
#include<fstream>

using namespace std;

class student
{
    private:
        char name[30];
        int age;
    public:
        void getData(void)
        {
            cout << "Enter name: ";cin.getline(name,30):
            cout << "Enter age: ";cin>>age;
        }
        
        void showData(void)
        {
            cout << "name: " << name << " ,Age: " << age << endl;
        }
};

int main()
{
    student s;
    ofstream file;
    
    file.open("aaa.txt",ios::out);
    if(!file)
    {
        cout << "Error in creating file.." << endl;
        return 0;
    }
    
    cout << "\nFile created successfully" << endl;
    
    s.getData();
    file.write((char*)&s, sizeof(s));
    file.close();
    cout << "\n file saved and closed succesfully." << endl;
    
    ifstream file1;
    file1.open("aaa.txt",ios::in);
    if(!file1)
    {
        cout << "Error in opening file..";
        return 0;
    }
    
    file1.read((char*)&s, sizeof(s));
    
    s.showData();
    file1.close();
    return 0;
}
