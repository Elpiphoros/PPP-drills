/*
1. Define template<typename T> struct S { T val; };.
2. Add a constructor, so that you can initialize with a T.
3. Define variables of types S<int>, S<char>, S<double>, S<string>, and S<vector<int>>; initialize them with
values of your choice.
4. Read those values and print them.
5. Add a function template get() that returns a reference to val.
6. Put the definition of get() outside the class.
7. Make val private.
8. Do 4 again using get().
9. Add a set() function template so that you can change val.
10. Replace set() with an S<T>::operator=(const T&). Hint: Much simpler than §19.2.5.
11. Provide const and non-const versions of get().
12. Define a function template<typename T> read_val(T& v) that reads from cin into v.
13. Use read_val() to read into each of the variables from 3 except the S<vector<int>> variable.
14. Bonus: Define input and output operators (>> and <<) for vector<T>s. For both input and output use a { val, val, val }
format. That will allow read_val() to also handle the S<vector<int>> variable.
Remember to test after each step.
*/

#include "../std_lib_facilities.h"

/*
情况１：
 template <class 形参名，class 形参名，......> 返回类型 函数名(参数列表)
{
    函数体
}
其中template和class是关键字，class可以用typename 关键字代替，在这里typename 和class没区别，<>括号中的参数叫模板形参，模板形参和函数形参很相像，模板形参不能为空。
eg:
template <class T> void swap(T& a, T& b){}，
当调用这样的模板函数时类型T就会被被调用时的类型所代替，比如swap(a,b)其中a和b是int 型，这时模板函数swap中的形参T就会被int 所代替，模板函数就变为swap(int &a, int &b)。
而当swap(c,d)其中c和d是double类型时，模板函数会被替换为swap(double &a, double &b)，这样就实现了函数的实现与类型无关的代码。
注意：对于函数模板而言不存在 h(int,int) 这样的调用，不能在函数调用的参数中指定模板形参的类型，
     对函数模板的调用应使用实参推演来进行，即只能进行 h(2,3) 这样的调用，或者int a, b; h(a,b)。


情况２：
template<class  类型参数名（比如叫U 就是一个名字），class 形参名，…>   class 类名
{ ... };
eg: template<class T> class A{public: T a; T b; T hy(T c, T &d);};
1.在类A中声明了两个类型为T的成员变量a和b，还声明了一个返回类型为T带两个参数类型为T的函数hy。
2.类模板对象的创建：比如一个模板类A，则使用类模板创建对象的方法为A<int> m;在类A后面跟上一个<>尖括号并在里面填上相应的类型，这样的话类A中凡是用到模板形参的地方都会被int 所代替。
当类模板有两个模板形参时创建对象的方法为A<int, double> m;类型之间用逗号隔开。
3.对于类模板，模板形参的类型必须在类名后的尖括号中明确指定。
比如A<2> m;用这种方法把模板形参设置为int是错误的（编译错误：error C2079: 'a' uses undefined class 'A<int>'），类模板形参不存在实参推演的问题。
也就是说不能把整型值2推演为int 型传递给模板形参。要把类模板形参调置为int 型必须这样指定A<int> m。
*/

/*
1:　Define template<typename T> struct S { T val; };
The C++ notation for introducing a type parameter T is the template<typename T> prefix, meaning “for all types T.”
 T is a parameter that can be given “values” such as double, int, string, vector<Record>, and Window*.
*/
template<class T> struct S      //struct默认为public 所以这里没有申明
{
    S() : val(T()) { }      //default constructor
    S(T d) : val(d) { }     // 2: Add a constructor S, so that you can initialize with a T.
    T& operator=(const T&); // 10:  Replace set() with an S<T>::operator=(const T&).
    T& get();               // 5: Add a function template get() that returns a reference to val!
    const T& get() const;   // 11: Provide const and non-const versions of get(). 模板特化
    void set(const T& d);   // 9: Add a set() function template so that you can change val.
private:
    T val;                  //7: Make val private. (date_type value)
};

template<class T> T& S<T>::operator=(const T& d)
{
    val = d;
    return val;
}


/*
在类模板外部定义成员函数的方法为：
template<模板形参列表> 函数返回类型 类名<模板形参名>::函数名(参数列表){函数体}

比如有两个模板形参T1，T2的类A中含有一个void h()函数，则定义该函数的语法为：
template<class T1,class T2> void A<T1,T2>::h(){}
*/
template<class T> T& S<T>::get() { return val; }                    //6: Put the definition of get() outside the class.

template<class T> const T& S<T>::get() const { return val; }        //11: Provide const versions of get().

template<class T> void S<T>::set(const T& d) { val = d; }           //9:Add a set() function template so that you can change val.

// 12: Define a function template<typename T> read_val(T& v) that reads from cin into v.
template<class T> istream& operator>>(istream& is, S<T>& ss)
{
    T v;
    cin >> v;
    if (!is) return is;
    ss = v;
    return is;
}

template<class T> void read_val(T& v)
{
    cin >> v;
}

// -----------------------------------------------------------------------------

// Drill 14
template<class T> ostream& operator<<(ostream& os, const vector<T>& d)
{
    os << "{ ";
    for (int i = 0; i<d.size(); ++i) {
        os << d[i];
        if (i<d.size()-1) os << ',';
        os << ' ';
    }
    os << "}";
    return os;
}

template<class T> istream& operator>>(istream& is, vector<T>& d)
{
    char ch1;
    char ch2;
    T temp;
    vector<T> v_temp;
    is >> ch1;
    if (!is) return is;
    if (ch1!='{') {
        is.clear(ios_base::failbit);
        return is;
    }
    while (cin>>temp>>ch2 && ch2==',') {
        v_temp.push_back(temp);
    }
    if (ch2!='}') {
        is.clear(ios_base::failbit);
        return is;
    }
    v_temp.push_back(temp); // ch2=='}', read last value

    // copy temp vector only now so d is not changed if input fails
    d = v_temp;
}

// -----------------------------------------------------------------------------

int main()
try {
    // 3: Define variables of types S<int>, S<char>, S<double>, S<string>, and S<vector<int>>; initialize them with values of your choice.
    S<int> s_int (5);                //S(T d) : val(d) { } ; s_int is the name of the int variable.
    S<char> s_char ('x');
    S<double> s_dbl (3.14);
    S<string> s_strg ("String1");
    
    vector<int> vi;                  //first of all we define a vector named vi
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);                 //initalize the vector
    S<vector<int>> s_v_int (vi);     //define the variable of vector named s_v_int

    
/*  //4: Read those values and print them.
    cout << "s_int: " << s_int.val << endl;
    cout << "s_char: " << s_char.val << endl;
    cout << "s_dbl: " << s_dbl.val << endl;
    cout << "s_strg: " << s_strg.val << endl;
    for (int i = 0; i<s_v_int.val.size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.val[i] << endl;
*/

    // 8: Do 4 again using get().
    cout << "s_int: " << s_int.get() << endl;
    cout << "s_char: " << s_char.get() << endl;
    cout << "s_dbl: " << s_dbl.get() << endl;
    cout << "s_strg: " << s_strg.get() << endl;
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << endl;

    // 9: Add a set() function template so that you can change val.
    s_int.set(55);
    s_char.set('y');
    s_dbl.set(4.14);
    s_strg.set("String2");
    vi[1] = 22;
    s_v_int.set(vi);
    cout << "\ns_int: " << s_int.get() << endl;
    cout << "s_char: " << s_char.get() << endl;
    cout << "s_dbl: " << s_dbl.get() << endl;
    cout << "s_strg: " << s_strg.get() << endl;
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << endl;

    // 10: Replace set() with an S<T>::operator=(const T&).
    s_int = 66;
    s_char = 'z';
    s_dbl = 5.14;
    s_strg = "String3";
    vi[1] = 33;
    s_v_int = vi;
    cout << "\ns_int: " << s_int.get() << endl;
    cout << "s_char: " << s_char.get() << endl;
    cout << "s_dbl: " << s_dbl.get() << endl;
    cout << "s_strg: " << s_strg.get() << endl;
    for (int i = 0; i<s_v_int.get().size(); ++i)
        cout << "s_v_int[" << i << "]: " << s_v_int.get()[i] << endl;

    // 11: Provide const versions of get().
    const S<int> c_s_int(5);
    cout << "\nc_s_int: " << c_s_int.get() << endl;

    // 13: Use read_val() to read into each of the variables from 3 except the S<vector<int>> variable.
    cout << "\ns_int: ";
    read_val(s_int);
    cout << "s_char: ";
    read_val(s_char);
    cout << "s_dbl: ";
    read_val(s_dbl);
    cout << "s_strg: ";
    read_val(s_strg);
    cout << "\ns_int: " << s_int.get() << "\n";
    cout << "s_char: " << s_char.get() << "\n";
    cout << "s_dbl: " << s_dbl.get() << "\n";
    cout << "s_strg: " << s_strg.get() << "\n\n";

    /*
    14: Bonus: Define input and output operators (>> and <<) for vector<T>s. For both input and output use a { val, val, val }
            format. That will allow read_val() to also handle the S<vector<int>> variable.
            Remember to test after each step.
    */
    cout << "\ns_v_int: ";
    read_val(s_v_int);
    cout << "\ns_v_int: " << s_v_int.get() << endl;

}
catch (exception& e)
{
    cerr << "Exception: " << e.what() << endl;
}
catch (...)
{
    cerr << "Exception\n";
}
