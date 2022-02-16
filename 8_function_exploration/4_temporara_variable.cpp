// cubes.cpp -- regular and reference arguments
//reference 必須了解的特性 !!!!!!!!!!!!!!!!!!!!
#include <iostream>
double refcube( double &ra);
int main ()
{
    using namespace std;
    double side = 3.0;
    double *pd = &side;
    double &rd = side;
    long edge = 5L;  //  Compiler不知道5L(long)是甚麼
    double lens[4] = {2.0, 5.0 ,10.0, 12.0};
    double c1 = refcube(side);      // ra is side
    cout << "1." <<side << endl;
    double c2 = refcube(lens[2]);   // ra is len[2] 
    cout << "array[2]" <<lens[2] << endl;


    cout << "201:." << rd << endl;
    double c3 = refcube(rd);        // ra is rd is side
    cout << "2." << side << endl;
    double c4 = refcube(*pd);       // ra  is *pd is side
    cout << "3." << side << endl;
    //double c5 = refcube(edge);      //ra is temporary variable
    //double c6 = refcube(7.0);       //ra is temporary variable
    //double c7 = refcube(side + 1.0);//ra is temporary variable
    //故意寫錯的程式
    // 2021/2/3 c++ 會報錯(17、18、19行)， 但舊的c++compiler可能只會報warning，若看到"暫時變數"的警告，請別忽視。

    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    cout << c4 << endl;

   
    return 0;
}


double refcube( double &ra)
{
    ra *= ra * ra;
    return ra; 
}

