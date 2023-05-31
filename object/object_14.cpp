//成员变量和成员函数分开存储
#include <iostream>
using namespace std;

class Person{
    int m_A;//非静态成员变量 属于类对象上

public:
    static int m_B;//静态成员变量并不属于类对象上

    void func(){};//非静态成员函数 只一份就可以，不属于类的对象上
    
    static void func2(){};//静态成员函数 只一份 不属于类对象上
};

int Person::m_B = 10;
void test1(){
    Person p;
    //空对象占用的内存空间为？ 答案为1
    //C++编译器会给每个空对象也分配一个字节的空间，为了区分空对象占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout << "size of person " << sizeof(p) <<endl;
}

void test2(){
    Person p;
    cout << "size of person " << sizeof(p) <<endl;
}
int main() {
    test2();    
    return 0;
}