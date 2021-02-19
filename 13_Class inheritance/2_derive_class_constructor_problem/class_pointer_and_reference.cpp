#include <iostream>
#include "tabtenn1.h"
#include "tabtenn1.cpp"

using namespace std;
void Show(const TableTennisPlayer &rt);
int main ( void )
{
    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);

    TableTennisPlayer & rt = rplayer1;   //基礎類別reference 可以參考 衍生類別 的物件!!!!!!!!!!!!!!!!(重點)
    TableTennisPlayer * pt = &rplayer1;  //基礎類別指標      可以指向 衍生類別 的物件  !!!!!!!!!!!!!!!!(重點)
                                         //但只會有TableTennisPlayer 的成員資料， 沒有RatedPlayer 的成員資料
                                         //所以 基礎類別指標或reference只能呼叫 基礎類別的成員函數
                                         //所以 不能使rt或pt呼叫 衍生類別(RatedPlayer)的成員函數

    //RatedPlayer & rt2 =  player1;   //not allowed                              
    //RatedPlayer * pt2 =  &player1;  //not allowed     //衍生類別 的指標和reference 不能只向或參考 基礎類別 的物件

    cout << &rt << endl;
    cout << pt << endl;  //&rt 與 pt 一樣

    Show(player1);   //work with TableTennisPlayer argument
    Show(rplayer1);  //work with RatedPlayer argument

////////////////////////////////////////////////////////////////////////////////////////////////
    /*第12章內容， 搭配reference 相容性質*/
    /*初始化*/
    /*reference 相容性質，可以使 基礎類別物件 初始化為 衍生物件  如下:*/
    /*reference 相容性質，可以用 衍生物件 來初始化 基礎類別物件*/
    RatedPlayer olaf1(1141, "Pete", "Parker", true);
    TableTennisPlayer olaf2(olaf1); /*要完全匹配olaf2，其建構函數應為 TableTennisPlayer(const RatedPlayer & tp)*/
                                    /*我們類別沒有定義TableTennisPlayer(const RatedPlayer & tp) 建構函數*/
                                    /*那麼編譯器 就會產生 implicit copy constructor(第12章內容)*/
                                    /*自動產生TableTennisPlayer(const RatedPlayer & tp) [implicit copy constructor]*/
    /*指定運算子 operator=()*/
    /*同樣的，也可將RatedPlayer物件 指定給 TableTennisPlayer基礎物件*/
    RatedPlayer olaf1(1141, "Pete", "Parker", true);
    TableTennisPlayer winner;
    winner = olaf1; /*使用的是 隱函式多載的指定運算子*/
//////////////////////////////////////////////////////////////////////////////////////////////////


    return 0;
}

//基礎類別(TableTennisPlayer)reference 可以參考 衍生類別 的物件， 所以Show 的參數也可以放RatedPlayer物件。
void Show(const TableTennisPlayer &rt)
{
    cout << "Name: ";
    rt.Name();
    cout << "\nTable: ";
    if(rt.HasTable())
        cout << "yes\n";
    else
        cout << "no\n";
}