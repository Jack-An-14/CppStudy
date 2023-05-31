//继承同名成员处理方式
//问题：当子类与父类出现同名成员，如何通过子类对象，访问到子类或父类总的同名成员？
//访问子类同名成员，直接访问
//访问父类的同名成员，加作用域

#include <iostream>
using namespace std;
class Base{
    public:
        Base(){
            m_A = 100;
        }
        int m_A;

        void print(){
            cout << "BASE print" << endl;
        }

        void print(int a) {
            cout << "BASE print int" << endl;
        }
};

class Son : public Base{
    public:
        Son(){
            m_A = 200;
        }
        int m_A;

        void print(){
            cout << "Son print" << endl;
        }
};

void test1(){
    Son s;
    cout << s.m_A << endl;
    //加作用域
    cout << s.Base::m_A << endl;
}

void test2(){
    Son s;
    s.print();
    //同样的访问语法
    s.Base::print();
    //如果子类中出现与父类同名的成员函数，子类的同名成员会隐藏掉父类中所有的同名成员函数
    //加作用域即可
    s.Base::print(10);
}
int main() {
    test1();
    test2();
    return 0;
}