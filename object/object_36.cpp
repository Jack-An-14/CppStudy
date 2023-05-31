//多态
#include <iostream>
using namespace std;

class Animal{
    public:
    //在speak前加关键字virtual
        virtual void speak(){
            cout << "animal speak" << endl;
        }
};

class Cat : public Animal{
    public:
        void speak(){
            cout << "cat speak" << endl;
        }
};

class Dog : public Animal{
    public:
    //重写  函数返回值类型 函数名 参数列表 完全相同
        void speak(){
            cout << "Dog speak" << endl;
        }
};

//地址早绑定，在编译阶段就确定了函数的地址
//如果想执行猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
//动态多态满足条件
//1、有继承关系
//2、子类要重写父类的虚函数

//动态多态使用
//父类的指针或者引用 指向子类对象
void doSpeak(Animal & animal){
    animal.speak();
}

void test1(){
    Cat cat;

    //C++中允许父子之间的类型转换
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}
int main(){
    test1();
    return 0;
}