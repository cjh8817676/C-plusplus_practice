#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char str[10];
    char str2[10];
    cout << "Enter a string: ";
    gets(str);
    cout << "Enter a string: ";
    gets(str2);
    cout << "You entered: " << str;
    cout << "You entered: " << str2;
    
    return 0;
}