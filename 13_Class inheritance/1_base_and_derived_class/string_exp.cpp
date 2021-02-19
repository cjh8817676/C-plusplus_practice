#include <string>
#include <iostream>
using std::string;
using namespace std;
//在TableTennisPlayer player1("Chuck", "Blizzard", true); 時可以互相通用是因為有各種不同參數型態的建構子才得以成立
int main()
{
    string s1 = "penguin";  // 1.用 C型態字串 初始化 string物件
    char * str1 = "tiger";
    string & s2 = s1;     // 用reference參考物件
    //string & fn 在接收到 C形式字串

    //string & fn = str1; //C型態字串(char * str1) 與  string & fn型態不合
    //char * str3 = s1;   //                                     型態不合

    char * str4 = str1;



    cout << str1 << endl;
    cout << str4 << endl;
    

    return 0;
}
