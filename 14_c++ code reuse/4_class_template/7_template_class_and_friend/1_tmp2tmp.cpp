// tmp2tmp.cpp -- template friends to a template class
#include <iostream>
using std::cout;
using std::endl;

// template prototypes
template <typename T> void counts();
template <typename T> void report(T &);

// template class
template <typename TT>
class HasFriendT
{
private:
    TT item;
    static int ct;
public:
    HasFriendT(const TT & i) : item(i) {ct++;}
    ~HasFriendT() { ct--; }
    friend void counts<TT>(); // counts<TT>()  的<TT> ， 在使用的時候必須藉由 counts<int>()達到特定化， 此為:限制樣板夥伴函數
    friend void report<>(HasFriendT<TT> &); // HasFriendT<TT> 的<TT> ， 在使用的時候可以藉由 "引數"達到特定化。此為:限制樣板夥伴函數
};

template <typename T>
int HasFriendT<T>::ct = 0;

// template friend functions definitions
template <typename T>
void counts()
{
    cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
    cout << "template counts(): " << HasFriendT<T>::ct << endl;
}

template <typename T>
void report(T & hf)
{
    cout << hf.item << endl;
}

int main()
{
    counts<int>();
    HasFriendT<int> hfi1(10);
    HasFriendT<int> hfi2(20);
    HasFriendT<double> hfdb(10.5);
    report(hfi1);  // generate report(HasFriendT<int> &)
    report(hfi2);  // generate report(HasFriendT<int> &)
    report(hfdb);  // generate report(HasFriendT<double> &)
    cout << "counts<int>() output:\n";
    counts<int>();    //counts<int>() 表示 "特定化" 為 HasFriendT<int>而已， 所以稱為 "限制樣板"夥伴函數
    cout << "counts<double>() output:\n";
    counts<double>(); //counts<double>() 表示 "特定化"為 HasFriendT<double>而已，所以稱為 "限制樣板"夥伴函數
    // std::cin.get();
    return 0; 
}
