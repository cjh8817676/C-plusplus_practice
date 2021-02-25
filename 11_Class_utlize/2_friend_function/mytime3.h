// mytime3.h -- Time class with friends
#ifndef MYTIME3_H_
#define MYTIME3_H_
#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    void show() { std::cout << "hours:" << hours << " minutes: " << minutes ;}
    friend void show(const Time & t) {std::cout << "hours:" << t.hours << " minutes: " << t.minutes ;} 
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double n) const;                    //宣告原形函式(一般成員函式)                         只能(Time類別 * double)
    //原形函式(19行) 也可表示成 Time operator*(const Time & t, double m)
    
    friend Time operator*(double m, const Time & t)    //先宣告原形函式才能宣告 夥伴函式(注意:他雖在類別裡，但他是非成員函式)也可(double * Time類別)[對照參數順續]
        { return t * m; /*夥伴函數呼叫 第19行(在這裡並沒有存取私有類別)  */}   // inline definition

    friend std::ostream & operator<<(std::ostream & os, const Time & t); //只需令 << 為Time的夥伴即可(因為只要存取Time的private)

};
#endif
