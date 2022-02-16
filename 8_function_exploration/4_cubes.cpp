// cubes.cpp -- regular and reference arguments
//reference 必須了解的特性 !!!!!!!!!!!!!!!!!!!!
#include <iostream>
double cube(double a);
double refcube( double &ra);
double refcube2(const double &ra);
int main ()
{
    using namespace std;
    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);                 //refcube 修改了main中x的值 
    //cout << refcube(x + 3.0);          //錯誤:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    cout << " = cube of " << x << endl;
    x = 3.0;
    cout << refcube2(x);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
    cout << " = cube of " << x << endl;

    //double z =refcube(x + 3.0); // 會編不過， 因為"x+3.0不是變數"!!!!!
    
    //x + 3.0 = 5.0 // nonsensical  因為"x+3.0不是變數"

    // cin.get();
    return 0;
}

double cube(double a)
{
    a *= a * a;
    return a;
}

double refcube( double &ra)
{
    ra *= ra * ra;
    return ra; 
}

double refcube2(const double &ra) //加上 const ， 才不會導致main裡的資料改變。
{
    return ra*ra*ra; 
}
