//usetime3.cpp -- using the fourth draft of the Time class
// compile usetime3.cpp and mytime3.cpp together
#include <iostream>
#include "mytime3.h"
#include "mytime3.cpp"

int main()
{
    using std::cout;
    using std::endl;
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida and Tosca:\n";
    cout << aida<<"; " << tosca << endl;   //cout 可以直接印出類別了，因為"多載運算子"與"夥伴函式"的結合!!!!!
    temp = aida + tosca;     // operator+()
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida* 1.17;  // member operator*()     operator*(aida,1.17)
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10.0 * Tosca: " << 10.0 * tosca << endl;   //double 與 Time類別 的* 可以左右互換了
    //(呼叫夥伴函數 operator*(double, const Time & t)-->operator*(10.0,tosca))
	// std::cin.get();
    return 0; 
}
