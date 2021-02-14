#include <iostream>
int main()
{
    using namespace std;

    int rats = 101;
    int *pt = &rats;
    int & rodents = *pt;  // reference 參考 指標
    int bunnies = 50;

    cout << "rats address: " << &rats << endl;
    cout << "pt value " << pt << endl;
    cout << "rodents address :" << &rodents << endl;
    cout << "rodents content :" << rodents << endl;
    cout << "bunnies address :" << &bunnies << endl;
    pt = &bunnies;        

    cout << "after (pt = &bunnies;) rodents address :" << &rodents<< endl;
    cout << "after (pt = &bunnies;) rodents ???V????r :" << rodents<<endl;

    rodents = bunnies;

    cout << "after (rodents = bunnies;) rodents address :" << &rodents<< endl;
    cout << "after (rodents = bunnies;) rodents ???V????r :" << rodents;



}