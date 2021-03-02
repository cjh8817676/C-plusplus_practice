//usetime3.cpp -- using the fourth draft of the Time class
// compile usetime3.cpp and mytime3.cpp together
#include <iostream>
#include "mytime3.h"
#include "mytime3.cpp"

using namespace std;

int main()
{
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;
                           //" cout << aida" 這是結合 運算子多載(<<) 以及 夥伴函數 的觀念。 
    cout << aida << endl;  // 利用 夥伴函數， 可以印出  ""藉由aida物件存取的Time私有成員""。

    aida.show();  //  利用 一般成員函數， 印出  aida物件的私有成員。  (需要用物件呼叫。因為是成員函數)
    cout << endl;  
    show(aida);   //  利用 夥伴函數， 印出  aida物件的私有成員。     (不需要用物件呼叫。所以是 非成員函數) 只要函式的引數放對類別。

    /*並不行用以下方是印出:*/
    //cout << aida.hours; 
    //cout << aida.minutes; 


    return 0;
}