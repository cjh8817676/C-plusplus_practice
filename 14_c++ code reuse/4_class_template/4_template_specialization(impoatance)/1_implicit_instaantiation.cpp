// twod.cpp -- making a 2-d array
/*與資料夾2 一樣的檔案*/
#include <iostream>
#include "arraytp.h"
int main(void)
{
    using std::cout;
    using std::endl;
    ArrayTP<int, 10> sums;   //implicit instantiation 隱式實體化
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
