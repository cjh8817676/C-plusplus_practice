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
        cout << "注意------" << endl;
        callme2(headline2);                      //call by value 會出問題(若是不知道為甚麼會出問題，以後就盡量使用call by reference就沒事了)
        cout << "headline2: " << headline2 << "   出現奇怪的字串內容(被刪掉了)" << endl;
        cout << "注意^^^^^^" << endl;
        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;     //將sports用於"初始化"sailor(物件的初始化可以直接使用其他物件)，但是num_strings 沒有++
                                        //因為是將sports的資料複製過去的。
        cout << "sailor: " << sailor << endl;
        cout << "Assign one object to another:\n";
        StringBad knot;         //這個雖然會使num_strings ++
        knot = headline1;       //再C++ 這種處裡方式 會把 headline1 完全 複製過去
                                //所以可以發現 headline1 、 knot 參考同一個位址的物件阿!!!(在4_assignment_operator_invoke解決)
        cout << "knot: " << knot << endl; 
        cout << "Exiting the block.\n";
    }
    cout << "End of main()\n";    //會沒執行到這是因為"編譯器"的問題，較新的"編譯器"在顯示還剩-1個物件的情況下終止程式
                                  //這個機制稱為(GPF)General Protection Fault: 代表的是有一個程式想要存取不屬於他的記憶體空間。
                                  
    /*提示: 想執行完該程式，把call by value 的部分刪掉或都改成 call by reference就可以*/
    /*物件的 delete順序 與 new的順序  是相反的， 因為適用Stack去裝的*/
    /*所以最先被delete的物件是  knots 、 sailor 、spot 、headline2 、 headline1*/
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
    /*以headline2作為引數呼叫 會產生建構函式的呼叫(StringBad sb產生呼叫  但是num_strings 沒有++)*/
    /*物件sb 與 物件headline2 是用call by value 得方式傳遞，所以他們事實上是參考同個物件*/
    cout << "String passed by value:\n";
    cout << "    \"" << sb << "\"\n";
    /*這個函數結束之後會StringBad sb會被丟棄，此時呼叫解構函數，導致( static int num_strings --)*/
    /*這時又因為 物件 sb delete掉的記憶體位址 依然被headline2參考著，所以headline2也被刪掉啦!!!!!!!!!!!!!!!!!!!!!!!!*/
    
}

/*(54行的StringBad sb) 與 (29行) 有異曲同工之妙[都是用複製物件的方式((以值傳遞))]導致它們num_strings 沒有++*/
/*(num_strings 沒有++ 是因為在""複製物件""的時候  編譯器會產生(一)異種建構函數叫做  複製建構函數(copy structor))*/
/*"以值傳遞"表示會產生原始變數的副本，只要產生副本，編譯程式會自動使用 複製建構函數(copy structor)*/
/*複製建構函數(copy structor) 不知道要更新 static int num_strings*/
