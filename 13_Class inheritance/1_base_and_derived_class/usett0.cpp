// usett0.cpp -- using a base class
#include <iostream>
#include "tabtenn0.h"
#include "tabtenn0.cpp"

int main ( void )
{
    using std::cout;                                      //"Chuck"為C型態字串，但TableTennisPlayer建構函數的引數為const string &
    TableTennisPlayer player1("Chuck", "Blizzard", true); // "Chuck"、"Blizzard"是以C形式字串初始化String物件
    TableTennisPlayer player2("Tara", "Boomdea", false);  //C形式字串 與 const string & 不吻合。但為何能完美運作??
                                                // 可使用 string物件，或是C形式字串 當作TableTennisPlayer建構函數的引數
                                                //1.用string物件當作初始化用的引數的話: 會以const string & 為參數呼叫string建構函數 
                                                //2.用C形式字串當作初始化用的引數的話:會以 const char *為參數呼叫string建構函數 
    player1.Name();
    if (player1.HasTable())
        cout << ": has a table.\n";
    else
        cout << ": hasn't a table.\n";
    player2.Name();
    if (player2.HasTable())
        cout << ": has a table";
    else
        cout << ": hasn't a table.\n";
    // std::cin.get();
    return 0;
}
