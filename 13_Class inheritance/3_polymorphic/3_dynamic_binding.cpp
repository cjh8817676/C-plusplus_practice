// compile with brass.cpp
#include <iostream>
#include <string>
#include "brass.h"
#include "brass.cpp"

int main()
{
    BrassPlus ophelia;
    Brass *bp;//基礎類別指標      可以指向 衍生類別 的物件  !!!!!!!!!!!!!!!!(重點)
    bp = &ophelia;

    bp->ViewAcct(); // which version????????
    /*目前執行結果: Brass指標，指向的是BrassPlus， 所以ViewAcct()執行的結果會是 BrassPlus:ViewAcct()的版本。*/
                                                /*再次說明虛擬函式的行為，由呼叫 虛擬函式 的 "物件" 決定*/
                                                /*對虛擬成員函式，編譯程式使用的是  "動態繫結(dynamic binding)"*/
                                                /*(dynamic binding)是好的*/
    

    /*但是，假設ViewAcct() 在基礎類別中沒有設為虛擬成員函數，則 bp->ViewAcct(); 會根據指標型態(Brass) 呼叫Brass : ViewAcct();*/

                                                /* 對於非虛擬成員函數，編譯程式使用的是 "靜態繫結(static binding)"*/

    
}