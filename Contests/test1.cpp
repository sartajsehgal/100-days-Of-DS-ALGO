#include <iostream>
using namespace std;

class base {
    public:
    base()
    {
        cout<<"Hello this is base class\n";
    }
    virtual void display()
    {
        cout<<"Display of base"<<endl;
    }
    void hello()
    {
        cout<<"Hello"<<endl;
    }
};

class derived : public base {
    public:
    derived()
    {
        cout<<"Hello this is derived class\n";
    }
    void display()
    {
        cout<<"Display of derived"<<endl;
    }
};

int main()
{
    base *b;
    derived d;
    b=&d;
    b->display();
    b->hello();
}