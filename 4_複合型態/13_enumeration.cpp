#include <iostream>

enum spectrun {red,orange,yellow,green,blue,violet=25,indigo,ultraviolet};
int main()
{
    using namespace std;
    spectrun band; // band is a variable of type spectrum
    int color = blue;
    band = violet; // valid, blue is an enumerator
    //band = 2000; // invalid , 200 not an enumerator


    cout << band;
    band = spectrun(6);
    cout << endl;
    cout << band<< endl;

    cout << "-------------"<<endl;
    cout << color;
    color = 3 + red;
    cout << endl;
    cout << color;

    return 0;
}