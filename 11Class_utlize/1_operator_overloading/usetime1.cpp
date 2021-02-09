// usetime1.cpp -- using the second draft of the Time class
// compile usetime1.cpp and mytime1.cpp together
#include <iostream>
#include "mytime1.h"
#include "mytime1.cpp"

int main()
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    planning.Show();
    cout << endl;
 
    cout << "coding time = ";
    coding.Show();
    cout << endl;
    
    cout << "fixing time = ";
    fixing.Show();
    cout << endl;
////////////////////////////////////////
    total = coding + fixing;    // (運算子多載"+"本來只單純用於數字與數字，現在可以使結構(以自己的需求)相加"+")
    // operator notation
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;
/////////////////////////////////////////
    Time morefixing(3, 28);
    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;
//////////////////////////////////////////    
    total = morefixing.operator+(total);   // 也可以當持一個function使用
    // function notation
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;
    // std::cin.get();
    return 0;
}
