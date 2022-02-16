#include <iostream>
#include <string.h>
class Person
{
private:
    static const int LIMIT = 25;
    std::string lname; // Person's last name
    char fname[LIMIT]; // Person's first name

public:
    Person() {lname = ""; fname[0] = '\0' ;} // #1
    Person(const std::string & ln, const char * fn = "Heyyou"); //#2

    void show() const;       // firstname, lastname format
    void FormalShow() const; // lastname, firstname format
    ~Person();
};


Person :: Person(const std::string & ln, const char * fn)
{
    lname = ln;
    for (int i=0;i<strlen(fn)+1;i++)  //strlen(fn)+1 是重點喔
    {
        fname[i] = *(fn+i);
    }
}
Person::~Person()
{
}

void Person::show() const
{
    std::cout << fname << " " << lname;
}

void Person::FormalShow() const
{
    std::cout << lname << " " << fname;
}

