// cubes.cpp -- regular and reference arguments
//reference �����F�Ѫ��S�� !!!!!!!!!!!!!!!!!!!!
#include <iostream>
double cube(double a);
double refcube( double &ra);
double refcube2(const double &ra);
int main ()
{
    using namespace std;
    double x = 3.0;

    cout << cube(x);
    cout << " = cube of " << x << endl;
    cout << refcube(x);                 //refcube �ק�Fmain��x���� 
    //cout << refcube(x + 3.0);          //���~:                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    cout << " = cube of " << x << endl;
    x = 3.0;
    cout << refcube2(x);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
    cout << " = cube of " << x << endl;

    //double z =refcube(x + 3.0); // �|�s���L�A �]��"x+3.0���O�ܼ�"!!!!!
    
    //x + 3.0 = 5.0 // nonsensical  �]��"x+3.0���O�ܼ�"

    // cin.get();
    return 0;
}

double cube(double a)
{
    a *= a * a;
    return a;
}

double refcube( double &ra)
{
    ra *= ra * ra;
    return ra; 
}

double refcube2(const double &ra) //�[�W const �A �~���|�ɭPmain�̪���Ƨ��ܡC
{
    return ra*ra*ra; 
}
