#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vect.h"
#include "vect.cpp"

int main()
{   
    using namespace std;
    using VECTOR::Vector; // VECTOR為名稱空間， Vector為VECTOR底下的Class

    Vector shove = Vector(100,300);
    cout << shove <<endl;
    shove.polar_mode();
    cout << shove << "after change to pol" << endl;



    Vector shove2 = Vector(2,30,VECTOR::Vector::POL);
    cout << shove2;

    return 0;


}