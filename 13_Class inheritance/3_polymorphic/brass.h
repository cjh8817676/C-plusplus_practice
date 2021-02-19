// brass.h  -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_
#include <string>
// Brass Account Class
class Brass
{
private:
    std::string fullName;   //客戶姓名
    long acctNum;           //帳號
    double balance;         //餘額
public:
    Brass(const std::string & s = "Nullbody", long an = -1,
                double bal = 0.0); // 產生帳號
    void Deposit(double amt);      // 存款
    virtual void Withdraw(double amt);//提款  (虛擬成員函數)(virtual member function)
    double Balance() const;        //查詢餘額
    virtual void ViewAcct() const;//顯示帳號資訊 (虛擬成員函數)(virtual member function)
    virtual ~Brass() {}                       //虛擬解構函數  !!查看第5個 txt
};

//Brass Plus Account Class
class BrassPlus : public Brass
{
private:
    double maxLoan;    // 透支保護的上限金額
    double rate;       // 透支貸款的利率
    double owesBank;   // 目前欠銀行的透支總金額
public:
    BrassPlus(const std::string & s = "Nullbody", long an = -1,
            double bal = 0.0, double ml = 500,
            double r = 0.11125);
    BrassPlus(const Brass & ba, double ml = 500, 
		                        double r = 0.11125);
    virtual void ViewAcct()const; //顯示帳號資訊，比基礎類別還多的資訊        (polymorphic) 
    virtual void Withdraw(double amt); //提款 ， 比基礎類別新增 欠款上限的判斷(polymorphic)
    void ResetMax(double m) { maxLoan = m; } 
    void ResetRate(double r) { rate = r; };
    void ResetOwes() { owesBank = 0; }
};

#endif
