// usedma.cpp -- inheritance, friends, and DMA
// compile with dma.cpp
#include <iostream>
#include "dma.h"
#include "dma.cpp"
int main()
{
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4); //  lacks(沒有):"沒有"動態記憶體配置 的 衍生類別
    hasDMA map("Mercator", "Buffalo Keys", 5);// has (有): "有" 動態記憶體配置 的 衍生類別
    cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;
    cout << "Displaying lacksDMA object:\n";
    cout << balloon << endl;
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;
    lacksDMA balloon2(balloon);  //複製建構函數問題
    //lacksDMA balloon2 = balloon; //與上行同樣。 
    cout << "Result of lacksDMA copy:\n";
    cout << balloon2 << endl;
    hasDMA map2;
    map2 = map;  // 指定運算子 問題
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;
    // std::cin.get();
    return 0; 
}
