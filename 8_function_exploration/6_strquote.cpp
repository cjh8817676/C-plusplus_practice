// strquote.cpp  -- different designs
// 物件類別的reference
#include <iostream>
#include <string>
using namespace std;
string version1(const string & s1, const string & s2);
const string & version2(string & s1, const string & s2);  // has side effect
const string & version3(string & s1, const string & s2);  // bad design
const string & version3_5(string & s1, const string & s2);  
 
int main()
{
    string input;
    string copy;
    string result;

    cout << "Enter a string: ";
    getline(cin, input);
    copy = input;
    cout << "Your string as entered: " << input << endl;
    result = version1(input, "***");  //引數分別為 string 與 const char *兩種型態，為何可以編過??(引數都不是const string & 型態)
                                      //因為:1. "***" : string 類別有定義一個char *轉成string的機制。 
                                      //     2. input : 因為version1的 引數是const，能接受 const 與 非-const 資料
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
 
    result = version2(input, "###");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;  //原來的輸入被改變了

    cout << "Resetting original string.\n";
    input = copy;
    //result = version3(input, "@@@");
    result = version3_5(input, "@@@");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string: " << input << endl;
	// cin.get();
	// cin.get();
    return 0;
}

string version1(const string & s1, const string & s2)
{
    string temp;

    temp = s2 + s1 + s2;
    return temp;
}

const string & version2(string & s1, const string & s2)   // has side effect
{
    s1 = s2 + s1 + s2;
// safe to return reference passed to function
    return s1; 
}

const string & version3(string & s1, const string & s2)   // bad design 有錯誤 不可執行
{
    string temp;

    temp = s2 + s1 + s2;
// unsafe to return reference to local variable
    return temp;
}
const string & version3_5(string & s1, const string & s2)   // version3 改 可執行
{
    string *temp = new string;
    *temp = s2 + s1 + s2;
    string & rodents = *temp;

    return rodents;
}