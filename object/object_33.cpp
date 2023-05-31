//继承同名静态成员处理方式
//问题：继承中同名的静态成员在子类对象如何进行访问
//静态成员和非静态成员出现同名，处理方式一样
#include <iostream>
using namespace std;
class Base{
    public:
        static int m_A;
        static void func(){
            cout << "Base static" << endl;
        }
};
int Base::m_A = 100;

class Son : public Base{
    public:
        static int m_A;
        static void func(){
            cout << "Son static" << endl;
        }
};
int Son::m_A = 200;

void test1(){
    //
    Son s1;
    //输出200，访问的是Son中的m_A
    cout << s1.m_A << endl;
    //输出100，访问的是Base中的m_A
    cout << s1.Base::m_A << endl;

    //通过类名
    cout << Son::m_A << endl;
    cout << Base::m_A << endl;
    //第一个::代表通过类名方式访问， 第二个::代表访问父类作用域下
    cout << Son::Base::m_A << endl;
}

void test2(){
    //通过对象访问
    Son s;
    s.func();
    s.Base::func();

    //通过类名来访问
    Son::func();
    Base::func();
    Son::Base::func();
}
int main(){
    // test1();
    test2();
    return 0;
}