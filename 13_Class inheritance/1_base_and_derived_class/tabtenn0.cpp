//tabtenn0.cpp -- simple base-class methods
#include "tabtenn0.h"
#include <iostream>
/*
TableTennisPlayer::TableTennisPlayer (const string & fn, 
    const string & ln, bool ht) : firstname(fn),
	    lastname(ln), hasTable(ht) {}*/

TableTennisPlayer::TableTennisPlayer (const string & fn, const string & ln, bool ht)
{                       
    firstname = fn;     //(usett0.cpp)在初始化物件的時候用的是C形式字串!!!
    lastname = ln;      //const string & fn 在接收到 C形式字串
	hasTable = ht;      //但是 (const string &)型態與 C形式字串型態不吻合
                        //C形式字串 跟 (const char * )才吻合  
                        /*第12章有介紹到String類別，還帶有參數為const char *的建構函數
                          而該建構函數會被自動使用，""來建構以C形式字串建構的string物件""*/
}

void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}
