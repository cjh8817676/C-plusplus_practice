#include <iostream>
#include "Person.h"

int main()
{
    using namespace std;
    //Person one;                        //use default constructor
    Person two("Symthecraft");         //use #2 with one default argument
    Person three("Dimwiddy", "Sam");   //use #2, no default
    /*one.show(); 
    cout << endl;
    one.FormalShow();
    cout << endl;*/

    two.show();
    cout << endl;
    two.FormalShow();
    cout << endl;
    cout << endl;

    three.show();
    cout << endl;
    three.FormalShow();

    return 0;
}