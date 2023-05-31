//const修饰成员函数
#include <iostream>
using namespace std;

class Person{
    public:
        Person(){}
    //this指针的本质 是指针常量 指针的指向是不可以修改的
    //const Person* const this;
    //在成员函数后面加const，本质修饰的是this指针，让this指针指向的值也不能修改
        void showPerson() const
        {
            m_B = 100;
            // this->m_A = 100;
            // this = NULL; this指针不可以修改指针的指向
        }
        
        void func(){
            cout << "func" << endl;
        }

        int m_A;
        mutable int m_B;    //特殊变量，即使在常函数中，也可以修改这个值，变量前+mutable; 常对象下也可以修改
};

void test1(){
    Person p;
    p.showPerson();
}

void test2(){
    const Person p; //在对象前+const，变为常对象
    p.m_A = 100;    //常对象不允许修改普通成员变量
    p.m_B = 100;

    //常对象只能调用常函数
    p.showPerson();
    //常对象不可以调用普通成员函数，因为普通成员函数可以修改成员变量
    p.func();
}

int main(){

    return 0;
}