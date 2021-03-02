// tempmemb.cpp -- template members
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class beta
{
private:
    template <typename V>  // nested template class member
    class hold
    {
    private:
        V val;
    public:
        hold(V v  = 0) : val(v) {}
        void show() const { cout << val << endl; }
        V Value() const { return val; }
    };
    hold<T> q;             // template object q 不一定
    hold<int> n;           // template object n 一直是 int 型態
public:
    beta( T t, int i) : q(t), n(i) {}

    template<typename U>   // template method
    U blab(U u, T t) { return (n.Value() + q.Value()) * u / t; }
    
    void Show() const { q.show(); n.show();} 
};

int main()
{
    beta<double> guy(3.5, 3.25);

    cout << "T was set to double\n"; //因為 beta<double>
    guy.Show(); // 因為guy第一開參數為3.5(double)，所以T 為 double。
    cout << "V was set to T, which is double, then V was set to int\n"; //V was set to T 因為20行  V was set to int 因為21行
    cout << guy.blab(10, 2.3) << endl; //因為第一個參數 為10(int)，所以U 被設為int
    cout << "U was set to int\n";
    cout << guy.blab(10.0, 2.3) << endl;//因為第一個參數 為10.0(double)，所以U 被設為int
    cout << "U was set to double\n";
    cout << "Done\n";
    // std::cin.get();
    return 0; 
}
