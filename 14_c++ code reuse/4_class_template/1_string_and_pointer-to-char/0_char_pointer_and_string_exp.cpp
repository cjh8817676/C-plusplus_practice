// stacktem.cpp -- testing the template stack class
#include <iostream>
#include <string>
#include <cctype>
#include "0_stacktp.h"
using std::cin;
using std::cout;
/*  stack<char *> 可以取代 stack<string> 嗎??  答案是可以。  但是需要注意一些問題。*/
int main()
{
    Stack<char *> st;   // create an empty stack for pointer-to-char  (用stack存放指標)
    char ch;
    //std::string po;  //有動態配置
    //char * po;       //只會產生指標，(能編譯成功，但cin的時候會出錯。)
    //char po[40];     // 型態不 匹配，(編譯會直接錯)
    char * po = new char[40]; //只會配置 一次記憶體， 導致 Stack裡的 Type items[MAX];  ，每一個都指向相同記憶體，所以顯示都會一樣
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && std::toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!std::isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                      cin >> po;
                      if (st.isfull())
                          cout << "stack already full\n";
                      else
                          st.push(po);
                      break;
            case 'P':
            case 'p': if (st.isempty())
                          cout << "stack already empty\n";
                      else {
                          st.pop(po);
                          cout << "PO #" << po << " popped\n";
                          break;
                      }
            case 'c': st.check();
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    // cin.get();
    // cin.get();
    return 0; 
}
