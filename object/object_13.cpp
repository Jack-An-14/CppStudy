//静态成员函数
#include <iostream>
using namespace std;
class Person{
public:
    static void func(){
        cout << "静态成员函数" << endl;
        m_A = 100;//静态成员函数可以访问静态成员变量
        m_B = 10;//静态成员函数不可以访问非静态成员变量，无法区分是哪个对象的m_B
    } 

    static int m_A;//静态成员变量
    int m_B;

    //静态成员函数也是有访问权限的
private:
    static void func2(){
        cout << "私有的静态成员函数" <<endl;
    }
};

int Person::m_A = 0;
void test1(){
    //1、通过对象访问
    Person p;
    p.func();

    //2、通过类名访问
    Person::func();
}
int main(){
    test1();
    Person::func2 (Inaccessible);//私有静态成员函数，类外无法访问
    return 0;
}