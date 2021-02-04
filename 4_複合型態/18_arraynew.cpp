// arraynew.cpp -- using the new operator for arrays
// 用 new 產生動態陣列
#include <iostream>
int main()
{
    using namespace std;
    double * p3 = new double [3]; // space for 3 doubles  (產生動態陣列)
    p3[0] = 0.2;                  // treat p3 like an array name
    p3[1] = 0.5;
    p3[2] = 0.8;
    cout << "p3[1] is " << p3[1] << ".\n";
    p3 = p3 + 1;                  // increment the pointer
    cout << "Now p3[0] is " << p3[0] << " and ";
    cout << "p3[1] is " << p3[1] << ".\n";
    p3 = p3 - 1;                  // point back to beginning (指標要回預設值才可以delete)
    delete [] p3;                 // free the memory  (中括號表示釋放整個陣列，而不是此指標所指的元素)
    //cin.get();
    return 0; 
}
