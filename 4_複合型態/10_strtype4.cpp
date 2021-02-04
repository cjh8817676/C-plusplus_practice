// strtype4.cpp -- line input

//需要一次讀取一行，而不只是單一單字時，需使用不同語法
#include <iostream>
#include <string>               // make string class available
#include <cstring>              // C-style string library
int main()
{
    using namespace std;
    char charr[20]; 
    string str;

    cout << "Length of string in charr before input: " 
         << strlen(charr) << endl;
    cout << "Length of string in str before input: "
         << str.size() << endl;
    cout << "Enter a line of text:\n";
    cin.getline(charr, 20);     // indicate maximum length  (來自 iostream)
    cout << "You entered: " << charr << endl;
    cout << "Enter another line of text:\n";
    getline(cin, str);          // cin now an argument; no length specifier !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! (來自 string )
    cout << "You entered: " << str << endl;
    cout << "Length of string in charr after input: " 
         << strlen(charr) << endl;
    cout << "Length of string in str after input: "
         << str.size() << endl;

     cout << "Address of string in charr after input: " 
         << &charr << endl;
    cout << "Address of string in str after input: "
         << &str << endl;


    // cin.get();

    return 0; 
}
