#ifndef WINE_H_
#define WINE_H_
#include <iostream>
#include <string>   
#include <valarray>
template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    T1 & first();
    T2 & second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 & aval, const T2 & bval) : a(aval), b(bval) { }
    Pair() {}
};

template<class T1, class T2>
T1 & Pair<T1,T2>::first()
{
    return a;
}
template<class T1, class T2>
T2 & Pair<T1,T2>::second()
{
    return b;
}


/*class wine*/
class Wine
{
    private:
        typedef std::valarray<int> ArrayInt;
        typedef Pair<ArrayInt, ArrayInt> PairArray;

        int y_kind_of_year;  //該種酒 有y種年份
        std::string wine_name;//酒的名稱
        PairArray *year_and_amount; 
    public:
        Wine (const char * s,int y,const int yr[] , const int bot[]);
        Wine (const char * l,int y);
        void Gotbottles();
        Wine & Label();
        void sum();
        void Show();
};

Wine:: Wine(const char * s,int y,const int yr[] , const int bot[])
{
    y_kind_of_year = y;
    wine_name = s;
    std::valarray<int> v_yr (yr, y);
    std::valarray<int> v_bot (bot, y);
    year_and_amount = new PairArray(v_yr,v_bot);
}
Wine:: Wine(const char * l,int y)
{
    y_kind_of_year = y;
    wine_name = l;
}
/*指定Wine物件具有y個年份，然後提示使用者輸入對應之釀造年分及瓶數*/
void Wine:: Gotbottles()
{
    std::cout << "Enter " << wine_name << " for " << y_kind_of_year << " year(s)" << std::endl;
    int *temp = new int[y_kind_of_year];   // int temp[y_kind_of_year] 會失敗。
    int *temp_bot = new int[y_kind_of_year];

    for (int i=0;i<y_kind_of_year;i++)
    {
        std::cout << "Enter year: ";
        std::cin >> *(temp+i);
        std::cout << std::endl << "Enter bottles for that year:"; 
        std::cin >> *(temp_bot+i);
        std::cout << std::endl;
    }

    for (int i=0;i<y_kind_of_year;i++)
    {   
        std::cout << *(temp+i) << std::endl;
        std::cout << *(temp_bot+i) << std::endl;
    }
    std::valarray<int> v_yr (temp, y_kind_of_year);
    std::valarray<int> v_bot (temp_bot, y_kind_of_year);

    year_and_amount = new PairArray(v_yr,v_bot);
}

void Wine:: Show()
{
    std::cout << "Wine: " <<wine_name << std::endl;
    std::cout << "Year:         Bottles" <<std::endl;

    for (int i=0;i<y_kind_of_year;i++)
    {
        std::cout << year_and_amount->first()[i] << "   ";
        std::cout << year_and_amount->second()[i] << std::endl;
    }
}


#endif