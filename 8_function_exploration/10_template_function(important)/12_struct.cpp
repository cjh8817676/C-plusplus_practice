// twotemps.cpp -- using overloaded template functions
#include <iostream>
template <typename T>     // original template
void Swap(T &a, T &b);

template <typename T>     // new template
void Swap(T *a, T *b, int n);

void Show(int a[]);
const int Lim = 8;

struct job
{
    char name[40];
    double salary;
    int floor;
};
//explicit specialization for the job typename
template <> void Swap<job> (job & j1, job &j2);   // 只有是 job型態才會呼叫該函式
int main()
{
    job worker1={"JOHN",1000.25,1};
    job worker2={"Sara",1001.25,2};

    std::cout << worker1.name << std::endl;
    std::cout << worker1.floor<< std::endl;
    std::cout << worker1.salary<< std::endl;

    std::cout << worker2.name<< std::endl;
    std::cout << worker2.floor<< std::endl;
    std::cout << worker2.salary<< std::endl;
    //C++允許 一個結構 指定給另一個結構
    Swap(worker1,worker2);
    std::cout << worker1.name << std::endl;
    std::cout << worker1.floor<< std::endl;
    std::cout << worker1.salary<< std::endl;

    std::cout << worker2.name<< std::endl;
    std::cout << worker2.floor<< std::endl;
    std::cout << worker2.salary<< std::endl;
    return 0;
}

template <typename T>
void Swap(T &a, T &b)    // general version
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <> void Swap<job> (job & j1, job & j2)    // 顯示特定化
{
    job temp;
    temp = j1;
    j1 = j2;
    j2 = temp;
}