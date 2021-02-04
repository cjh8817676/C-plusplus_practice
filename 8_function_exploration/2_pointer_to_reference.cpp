#include <iostream>
int main()
{
    using namespace std;

    int rats = 101;
    int & rodents = rats;  
    int *pt = &rodents;    // pointer 指向一個reference
    int bunnies = 50;

    cout << "rats address: " << &rats << endl;
    cout << "rodents address :" << &rodents << endl;
    cout << "rodents 數值 :" << rodents << endl;
    cout << "pt value " << pt << endl;
    cout << "*pt value " << *pt << endl;
    cout << "bunnies address :" << &bunnies << endl;
    pt = &bunnies;        // 接著pt改成指向bunnies，但不會改變rodents所reference的rats

    cout << "after (pt = &bunnies;) rodents address :" << &rodents<< endl;
    cout << "after (pt = &bunnies;) rodents 指向的數字 :" << rodents<<endl;

    rodents = bunnies;

    cout << "after (rodents = bunnies;) rodents address :" << &rodents<< endl;
    cout << "after (rodents = bunnies;) rodents 指向的數字 :" << rodents;



}