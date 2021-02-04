// numstr.cpp -- following number input with line input
#include <iostream>
int main()
{
    using namespace std;
    cout << "What year was your house built?\n";
    int year;
    cin >> year; //cin 完按下 ENTER產生的換行字元，會被下一次的cin給讀取到。
    cin.get();  //所以加上cin.get() ，可以解決(可以在這裡讀取換行字元，之後就可輸入地址了)
    cout << "What is its street address?\n";
    char address[80];
    cin.getline(address, 80);
    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
    cout << "Done!\n";
    // cin.get();
    return 0;
}
