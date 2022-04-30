/*
FIRST PART
1. Allocate an array of ten ints on the free store(heap store) using new.
2. Print the values of the ten ints to cout.
3. Deallocate the array (using delete[]).
4. Write a function print_array10(ostream& os, int* a) that prints out the values of a (assumed to have ten elements) to os.
5. Allocate an array of ten ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
6. Allocate an array of 11 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
7. Write a function print_array(ostream& os, int* a, int n) that prints out the values of a (assumed to have n elements) to os.
8. Allocate an array of 20 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
9. Did you remember to delete the arrays? (If not, do it.)
10. Do 5, 6, and 8 using a vector instead of an array and a print_vector() instead of print_array().
*/

#include "../std_lib_facilities.h"

// 4:Write a function print_array10(ostream& os, int* a) that prints out the values of a (assumed to have ten elements) to os.
void print_array10(ostream& os, int* a)
{
    for (int i = 0; i<10; ++i)
        os << a[i] << " ";
}

// 7: Write a function print_array(ostream& os, int* a, int n) that prints out the values of a (assumed to have n elements) to os.
void print_array(ostream& os, int* a, int n)
{
    for (int i = 0; i<n; ++i)
        os << a[i] << " ";
}

// 10: Do 5, 6, and 8 using a vector instead of an array and a print_vector() instead of print_array().
void print_vector(ostream& os, vector<int> v)
{
    for (int i = 0; i<v.size(); ++i)
        os << v[i] << " ";
}

int main()
try
{
    /* 
        1:Allocate an array of ten ints on the free store(heap store) using new.
        The C++ language makes this “free store” (also called the heap) available through an operator called new.
        This asks the C++ run-time system to allocate 10 ints on the free store and return a pointer to the first int to us. 
        We use that pointer to initialize our pointer variable ip.
    */
    int* ip = new int[10];

    // 2: Print the values of the ten ints to cout.
    cout << "task 2: print the 10 ints: \n";
    for (int i = 0; i<10; ++i)
        cout << ip[i] << " " ;
    cout << endl;

    /*
    3: Deallocate the array (using delete[]).
    There are two forms of delete:
    • delete p frees the memory for an individual object allocated by new.
    • delete[ ] p frees the memory for an array of objects allocated by new.
    */
    delete[] ip;
    
    // 5: Allocate an array of ten ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
    cout << "task 5: print the 10 ints: \n";
    int* ip2 = new int[10];
    for (int i = 0; i<10; ++i) //initialization loop
        ip2[i] = 100 + i;
    print_array10(cout,ip2);
    cout << endl;
    delete[] ip2;
    
    // 6: Allocate an array of 11 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
    cout << "task 6: print the 11 ints: \n";
    int* ip3 = new int[11];
    for (int i = 0; i<11; ++i)
        ip3[i] = 100 + i;
    print_array10(cout,ip3);
    cout << ip3[10] << "\n";
    cout << endl;
    delete[] ip3;
    
    // 8: Allocate an array of 20 ints on the free store; initialize it with the values 100, 101, 102, etc.; and print out its values.
    cout << "task 8: print the 20 ints: \n";
    int* ip4 = new int[20];
    for (int i = 0; i<20; ++i)
        ip4[i] = 100 + i;
    print_array(cout,ip4,20);
    cout << endl;
    delete[] ip4;
    
    // 10:  Do 5, 6, and 8 using a vector instead of an array and a print_vector() instead of print_array().
    cout << "task 10: \n";
    vector<int> v;
    for (int i = 0; i<10; ++i)
        v.push_back(100+i);
    print_vector(cout,v);
    cout << endl;

    vector<int> v2;
    for (int i = 0; i<11; ++i)
        v2.push_back(100+i);
    print_vector(cout,v2);
    cout << endl;

    vector<int> v3;
    for (int i = 0; i<20; ++i)
        v3.push_back(100+i);
    print_vector(cout,v3);
    cout << endl;
    
/*
SECOND PART
The second part focuses on pointers and their relation to arrays. Using print_array() from the last drill:
1. Allocate an int, initialize it to 7, and assign its address to a variable p1.
2. Print out the value of p1 and of the int it points to.
3. Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p2.
4. Print out the value of p2 and of the array it points to.
5. Declare an int* called p3 and initialize it with p2.
6. Assign p1 to p2.
7. Assign p3 to p2.
8. Print out the values of p1 and p2 and of what they point to.
9. Deallocate all the memory you allocated from the free store.
10. Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p1.
11. Allocate an array of ten ints, and assign its address to a variable p2.
12. Copy the values from the array pointed to by p1 into the array pointed to by p2.
13. Repeat 10–12 using a vector rather than an array.
*/
    
    // 1: Allocate an int, initialize it to 7, and assign its address to a variable p1.
    int i1 = 7;
    int* p1 = &i1;

    // 2: Print out the value of p1 and of the int it points to.
    cout << "task 2.2: \n";
    cout << "p1: " << p1 << endl;
    cout << "*p1: " << *p1 << endl;

    // 3: Allocate an array of seven ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p2.
    int* p2 = new int[7];
    for (int i = 0; i<7; ++i)
        p2[i] = pow(2,i);

    // 4: Print out the value of p2 and of the array it points to.
    cout << "task 2.4: \n";
    cout << "p2: " << p2 << "\n";
    cout << "print_array(cout,p2,7): ";
    print_array(cout,p2,7);
    cout << endl;

    // 5: Declare an int* called p3 and initialize it with p2.
    int* p3 = p2;

    // 6: Assign p1 to p2.
    p2 = p1;

    // 7: Assign p3 to p2.
    p2 = p3;

    // 8: Print out the values of p1 and p2 and of what they point to.
    cout << "task 2.8: \n";
    cout << "p1: " << p1 << "\n";
    cout << "*p1: " << *p1 << "\n";
    cout << "p2: " << p2 << "\n";
    cout << "*p2: " << *p2 << "\n";

    // 9: Deallocate all the memory you allocated from the free store.
    delete[] p2;
    p3 = 0;

    // 10: Allocate an array of ten ints; initialize it to 1, 2, 4, 8, etc.; and assign its address to a variable p1.
    p1 = new int[10];
    for (int i = 0; i<10; ++i)
        p1[i] = pow(2,i);

    // 11: Allocate an array of ten ints, and assign its address to a variable p2.
    p2 = new int[10];

    // 12: Copy the values from the array pointed to by p1 into the array pointed to by p2.
    cout << "task 2.12: \n";
    for (int i = 0; i<10; ++i)
        p2[i] = p1[i];
    print_array(cout,p2,10);
    cout << endl;

    // 13: Repeat 10–12 using a vector rather than an array.
    cout << "task 2.13: \n";
    vector<int> vec1;
    for (int i = 0; i<10; ++i)
        vec1.push_back(pow(2,i));
    vector<int> vec2;
    for (int i = 0; i<vec1.size(); ++i)
        vec2.push_back(vec1[i]);
    print_vector(cout,vec2);
    cout << endl;
    
}
catch (exception& e)
{
    cerr << "exception: " << e.what() << endl;
}
catch (...)
{
    cerr << "exception\n";
}   
    
