//纯虚函数和抽象类
//纯虚函数语法      virtual 返回值类型  函数名  （参数） = 0
//当类中有了纯虚函数，这个类也称为抽象类
#include <iostream>
using namespace std;

class Base{
    public:
    //纯虚函数
    //只要有一个纯虚函数，这个类称为抽象类。
        virtual void func() = 0;
};

class Son : public Base{
    public:
        void func(){
            cout << "Son的重写函数" << endl;
        }

};

void test1(){
    
    // Base b; 无法实例化抽象类
    //Son s; 子类必须重写父类的虚函数，否则就是抽象类，无法实例化
    Base * base = new Son;
    base->func();
    delete base;
}
int main(){
    test1();
    return 0;
}