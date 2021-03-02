// stacktp.h -- a stack template
#ifndef STACKTP_H_
#define STACKTP_H_
template <class Type>
class Stack
{
private:
    enum {MAX = 10};    // constant specific to class
    Type items[MAX];    // holds stack items
    int top;            // index for top stack item
public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Type & item); // add item to stack
    bool pop(Type & item);        // pop top into item
    void check();
    //friend review
    
    friend std::ostream & operator<<(std::ostream & os, const Stack<Type> & t)
    {
        for (int i=0;i<t.top;++i)
            os << t.items[i] ;
        return os;
    };

};

template <class Type>
Stack<Type>::Stack()
{
    top = 0;
}

template <class Type>
bool Stack<Type>::isempty()
{
    return top == 0;
}

template <class Type>
bool Stack<Type>::isfull()
{
    return top == MAX;
}

template <class Type>
bool Stack<Type>::push(const Type & item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
        return false;
}

template <class Type>
bool Stack<Type>::pop(Type & item)
{
    if (top > 0)
    {
        item = items[--top];  // ++i returns the value after it is incremented, while i++ return the value before it is incremented
        return true;
    }
    else
        return false; 
}

template <class Type>
void Stack<Type>::check()
{
    for (int i=0;i<top;++i)
        std::cout << items[i] << std::endl;
}


#endif
