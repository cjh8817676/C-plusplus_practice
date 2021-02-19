// vegnews.cpp -- using new and delete with classes
// compile with strngbad.cpp
#include <iostream>
using std::cout;
#include "strngbad.h"
#include "strngbad.cpp"
//#include "strngbetter.cpp"

void callme1(StringBad &);  // pass by reference
void callme2(StringBad);    // pass by value

int main()
{
    using std::endl;
    {
        cout << "Starting an inner block.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);                     //call by reference
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);                      //call by value  //初始化不一定會用copy constructor或是 指定運算子
                                                                  //但若運氣不好編譯器使用指定運算子，因為裡面沒有num_string++
        cout << "headline2: " << headline2 << "   no more strang string" << endl;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;     //利用copy constructor
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;        //有建構自己的 記憶體空間 ，所以已經有num_string ++           
        knot = headline1;      //只複製內容 ， 並沒有完全複製過去 ， 以避免 knot 與 headline 參考同一個位址的物件。 
        cout << "knot: " << knot << endl; 
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";    

    // std::cin.get();
    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "String passed by reference:\n";
    cout << "    \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{   
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
}


