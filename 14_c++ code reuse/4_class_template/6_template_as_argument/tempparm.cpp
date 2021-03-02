// tempparm.cpp � templates as parameters
#include <iostream>
#include "stacktp.h"
//template <class Thing>                       // 只可以放 int、double、std::string等型態。
                                             
template <template <typename T> class Thing> // 可以放自製的 容器(類別樣板)，告訴C++ 指定 型態參數T 給 型態參數Thing
class Crab                                   // 告訴C++ Thing為 樣板型態
{
private:
    Thing<int> s1;        //Stack<int> s1;
    Thing<double> s2;     //Stack<double> s2;
public:
    Crab() {};
    // assumes the thing class has push() and pop() members!!!!! 因為用的是Stack，這程式才可以跑。
    bool push(int a, double x) { return s1.push(a) && s2.push(x); }
    bool pop(int & a, double & x){ return s1.pop(a) && s2.pop(x); }
};
    
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    Crab<Stack> nebula; // 將 "樣板Stack" 類別 當成型態變數 傳入 樣板Crab類別
// Stack must match template <typename T> class thing   
    int ni;
    double nb;
    cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
    while (cin>> ni >> nb && ni > 0 && nb > 0)
    {
        if (!nebula.push(ni, nb))
            break;
    }
   
    while (nebula.pop(ni, nb))
           cout << ni << ", " << nb << endl;
    cout << "Done.\n";
    // cin.get();
    // cin.get();
    return 0; 
}
