// stone1.cpp -- user-defined conversion functions
// compile with stonewt1.cpp
#include <iostream>
#include "stonewt1.h"
#include "stonewt1.cpp"

int main()
{
    using std::cout;
    Stonewt poppins(9,2.8);     // 9 stone, 2.8 pounds
    Stonewt poppins2(9,2.8);     // 9 stone, 2.8 pounds
    double p_wt = poppins;      // implicit conversion
    double p_wt_sum = poppins + poppins2;   //poppins + poppins2的結果傳到一個暫時的物件，再把這個暫時的物件轉成double給p_wt_sum

    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << " pounds.\n";

    cout << "Sum of poppins => ";
    cout << "Poppins Sum: " << p_wt_sum << " pounds.\n";
    
    
	// std::cin.get();
    return 0; 
}
