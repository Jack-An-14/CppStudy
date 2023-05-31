//多继承语法
#include <iostream>
using namespace std;
class Base{
    public:
        Base(){
            m_A = 100;
        }
        int m_A;
};

class Base2{
    public:
        Base2(){
            m_A = 200;
        }
        int m_A;
};

class Son : public Base, public Base2{
    public:
        Son(){
            m_C = 100;
            m_D = 100;
        }

        int m_C;
        int m_D;
};


void test1(){
    Son s;
    cout << sizeof(s) << endl;
    //base 和 base2中都有m_A，直接访问会导致二义性，编译器不明白是哪一个m_A。加作用域
    cout << s.m_A << endl;
    cout << s.Base::m_A << endl;
    cout << s.Base2::m_A << endl;
    cout << s.m_C << endl;
    cout << s.m_D << endl;
}

int main(){
    test1();
    return 0;
}