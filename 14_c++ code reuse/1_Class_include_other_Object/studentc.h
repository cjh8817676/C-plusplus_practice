// studentc.h -- defining a Student class using containment
#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>   
#include <valarray>
class Student //Student 為 包含物件成員 的 類別
{   
private:
    typedef std::valarray<double> ArrayDb;
    std::string name;       // contained object : use a "string"           object for name
    ArrayDb scores;         // contained object : use   "valarray<double>" object for scores(成績陣列)
    // private method for scores output
    std::ostream & arr_out(std::ostream & os) const;  // 範例的 輸出成績 (目前不知道為甚麼要這樣設計!!)
    void grade_out (const ArrayDb & grades); //我自己設計的輸出成績  (一定要加 const)
public:
    Student() : name("Null Student"), scores() {}
    explicit Student(const std::string & s)
        : name(s), scores() {}
    explicit Student(int n) : name("Nully"), scores(n) {}   //產生 1個空名子 和 n個空成績
    Student(const std::string & s, int n)
        : name(s), scores(n) {}
    Student(const std::string & s, const ArrayDb & a)
        : name(s), scores(a) {}
    Student(const char * str, const double * pd, int n)
        : name(str), scores(pd, n) {}  // 把pd 前面 n 個成績放入 ArrayDb物件(score)
    ~Student() {}
    double Average() const;
    const std::string & Name() const;
    double & operator[](int i);
    double operator[](int i) const;
// friends
    // input
    friend std::istream & operator>>(std::istream & is,
                                     Student & stu);  // 1 word
    friend std::istream & getline(std::istream & is,
                                  Student & stu);     // 1 line
    // output
    friend std::ostream & operator<<(std::ostream & os,
                                     const Student & stu);
};

#endif
