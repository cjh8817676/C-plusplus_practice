// placenew2.cpp  -- new, placement new, no delete
#include <iostream>
#include <string>
#include <new>
using namespace std;
const int BUF = 512;

class JustTesting
{
private:
    string words;
    int number;
public:
    JustTesting(const string & s = "Just Testing", int n = 0) 
    {words = s; number = n; cout << words << " constructed\n"; }
    ~JustTesting() { cout << words << " destroyed\n";}
    void Show() const { cout << words << ", " << number << endl;}
};
int main()
{
    char * buffer = new char[BUF];       // get a block of memory

    JustTesting *pc1, *pc2;

    pc1 = new (buffer) JustTesting;      // place object in buffer
    pc2 = new JustTesting("Heap1", 20);  // place object on heap
    
    cout << "Memory block addresses:\n" << "buffer: "
        << (void *) buffer << "    heap: " << pc2 <<endl;
    cout << "Memory contents:\n";
    cout << pc1 << ": ";
    pc1->Show();
    cout << pc2 << ": ";
    pc2->Show();

    JustTesting *pc3, *pc4;
// fix placement new location
    pc3 = new (buffer + sizeof (JustTesting))
                JustTesting("Better Idea", 6);
    pc4 = new JustTesting("Heap2", 10);
    
    cout << "Memory contents:\n";
    cout << pc3 << ": ";
    pc3->Show();
    cout << pc4 << ": ";
    pc4->Show();
    
    delete pc2;           // free Heap1         
    delete pc4;           // free Heap2
// explicitly destroy placement new objects
/*這裡會發現 pc1、pc3與 pc2、pc4 的解構方式不一樣， 除了前面提到的 new 跟 delete 與 new[] delete[] 的成對使用
   但為甚麼不使用 delete []pc3、delete []pc1呢??  而需要明確呼叫解構函數???
   這是因為  雖然 new 跟 delete 可以一起使用，  但不包括"定位放置new"，因為C++沒有"定位釋放delete"，所以只好明確呼叫解構函數 
   一般 delete 對 "定位放置new" 不會有任何影響
   還要注意  delete 的順序要跟 new 相反， 不管有沒有定位(指定記憶體位置)*/

    //delete pc3;             
    //delete pc1;
    //delete []pc3;                 
    //delete []pc1;
    pc3->~JustTesting();  // destroy object pointed to by pc3
    pc1->~JustTesting();  // destroy object pointed to by pc1
    delete [] buffer;     // free buffer   不再只是單純釋放掉原來的buffer
    // std::cin.get();
    return 0;
}
