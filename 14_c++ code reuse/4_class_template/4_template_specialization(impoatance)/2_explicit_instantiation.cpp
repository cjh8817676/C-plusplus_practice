#include <iostream>
#include <cstdlib>
#include "arraytp.h"

template class ArrayTP<int, 10>; // generate ArrayTP<std::string, 100> class
                                  //整個 ""ArrayTP<int, 100>"" 是一個類別
template class ArrayTP<double, 10>; // generate ArrayTP<std::string, 100> class
                                  //整個 ""ArrayTP<std::string, 100>"" 是一個類別
int main()
{
    using std::cout;
    using std::endl;
    ArrayTP<int, 10> sums; //顯式 實體化
    ArrayTP<double, 10> aves;
    ArrayTP< ArrayTP<int,5>, 10> twodee; // 5cols 10rows。

        int i, j;
    
    for (i = 0; i < 10; i++)
    {
        sums[i] = 0;
        for (j = 0; j < 5; j++)
        {
            twodee[i][j] = (i + 1) * (j + 1);
            sums[i] += twodee[i][j];
        }
        aves[i] = (double) sums[i] / 10;
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout.width(2);  //用2個字元寬顯示
            cout << twodee[i][j] << ' ';
        }
        cout << ": sum = ";
        cout.width(3);
        cout  << sums[i] << ", average = " << aves[i] << endl;
    }
    
    cout << "Done.\n";
    // std::cin.get();
    return 0;

    
    

}

