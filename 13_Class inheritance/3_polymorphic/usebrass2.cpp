// usebrass2.cpp -- polymorphic example
// compile with brass.cpp
#include <iostream>
#include <string>
#include "brass.h"
#include "brass.cpp"
const int CLIENTS = 4;

int main()
{
   using std::cin;
   using std::cout;
   using std::endl;

   Brass * p_clients[CLIENTS]; //利用基礎物件指標，//基礎類別reference 可以參考 衍生類別 的物件!!!!!!!!!!!!!!!!(重點)
                                                 //基礎類別指標      可以指向 衍生類別 的物件  !!!!!!!!!!!!!!!!(重點)
                              //這個單一陣列中，可以表示一種型態以上(Brass、BrassPlus)的物件集合，這是同名異式(polymorphic)
   std::string temp;
   long tempnum;
   double tempbal;
   char kind;

   for (int i = 0; i < CLIENTS; i++)
   {
       cout << "Enter client's name: ";
       getline(cin,temp);
       cout << "Enter client's account number: ";
       cin >> tempnum;
       cout << "Enter opening balance: $";
       cin >> tempbal;
       cout << "Enter 1 for Brass Account or "
            << "2 for BrassPlus Account: ";
       while (cin >> kind && (kind != '1' && kind != '2'))
           cout <<"Enter either 1 or 2: ";
       if (kind == '1')
           p_clients[i] = new Brass(temp, tempnum, tempbal);
       else
       {
           double tmax, trate;
           cout << "Enter the overdraft limit: $";
           cin >> tmax;
           cout << "Enter the interest rate "
                << "as a decimal fraction: ";
           cin >> trate;
           p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
                                        tmax, trate);
        }
        while (cin.get() != '\n')
            continue;
   }
   cout << endl;
   for (int i = 0; i < CLIENTS; i++)
   {
       p_clients[i]->ViewAcct();   //這裡使用同名異式(polymorphic)
       cout << endl;
   }
              
   for (int i = 0; i < CLIENTS; i++)
   {
       delete p_clients[i];  // free memory
   }
   cout << "Done.\n";         
 /* code to keep window open 
   if (!cin)
      cin.clear();
   while (cin.get() != '\n')
      continue;
*/
   return 0; 
}
