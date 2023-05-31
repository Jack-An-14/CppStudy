//静态成员：在成员变量和成员函数之前加上关键字static
//静态成员变量和静态成员函数
#include <iostream>
using namespace std;
class Person{
    public:
        static int mA;
        //静态成员变量也有访问权限
    private:
        static int sMA;    
};
int Person::mA = 100;
int Person::sMA = 20;
void test1(){
    Person p;
    cout << p.mA <<endl;

    Person p2;
    p2.mA = 200;
    //共享同一份数据
    cout << p.mA << endl;
}

void test2(){
    //静态成员变量，不属于某个对象，所有对象都共享同一份数据
    //因此静态成员变量由两种访问方式

    //1、通过对象进行访问
    Person p;
    cout << p.mA << endl;
    //2、通过类名进行访问
    cout << Person::mA << endl;
    
    //这里的私有静态成员变量是不能访问的
    //cout << Person::sMA << endl;
}
int main(){

    test1();
    return 0;
}