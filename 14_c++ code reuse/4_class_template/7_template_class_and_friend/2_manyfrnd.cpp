// manyfrnd.cpp -- unbound template friend to a template class
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class ManyFriend
{
private:
    T item;
public:
    ManyFriend(const T & i) : item(i) {}                          //在類別內宣告樣板，可以產生無限制樣板夥伴函數。
    template <typename C, typename D> friend void show2(C &, D &);//這樣寫可以產生 無限制樣板夥伴函數
};

template <typename C, typename D> void show2(C & c, D & d)
{
    cout << c.item << ", " << d.item << endl;
}

int main()
{
    ManyFriend<int> hfi1(10);
    ManyFriend<int> hfi2(20);
    ManyFriend<double> hfdb(10.5);
    cout << "hfi1, hfi2: ";
    show2(hfi1, hfi2);
    cout << "hfdb, hfi2: ";
    show2(hfdb, hfi2);  //show2 為 ManyFriend<int> 和 ManyFriend<double> 的夥伴， 不受<>的限制，所以稱為無限制樣板夥伴函數
    // std::cin.get();
    return 0;
}
