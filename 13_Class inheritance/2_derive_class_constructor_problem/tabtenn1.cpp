//tabtenn1.cpp -- simple base-class methods
#include "tabtenn1.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer (const string & fn, 
    const string & ln, bool ht) : firstname(fn),
	    lastname(ln), hasTable(ht) {}
    
void TableTennisPlayer::Name() const
{
    std::cout << lastname << ", " << firstname;
}

// RatedPlayer methods
RatedPlayer::RatedPlayer(unsigned int r, const string & fn,
     const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)  // ": TableTennisPlayer(fn, ln, ht)" 是成員初始串列
                                /*^^^^^基礎類別的建構函數^^^^^^*/    // 他可以呼叫TableTennisPlayer的建構函數
{
    rating = r;
}

/*
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
    : TableTennisPlayer(tp), rating(r)
{
}*/
//22~26行 與 28~32 一樣
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
    : TableTennisPlayer(tp)    // TableTennisPlayer(tp)，tp的型態為const TableTennisPlayer &
{                              // 所以此呼叫 會引發 基礎類別(TableTennisPlayer) 的  "copy constructor-複製建構函數(編譯器產生)"
    rating = r;
}

