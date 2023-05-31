//构造函数的分类及调用
//分类
//按照参数分类  无参构造 和 有参构造
//按照类型分类  普通构造 和 拷贝构造
#include <iostream>
using namespace std;
class Person{
public:
    Person(){}

    Person(int a){
        age = a;
    }
    //拷贝构造函数
    Person(const Person & p){
        //将传入的变量的所有属性，拷贝到自己身上
        age = p.age;
    }
    int age;
};
//调用方法
int main() {
    //1、括号法
    //注意事项，调用默认构造函数的时候，不要加（）
    //因为下面这行代码，编译器会认为是一个函数的申明，不会认为在创建对象
    //Person p1()
    //2、显示法
    Person p1;
    Person p2 = Person(10);
    Person p3 = Person(p2);

    // Person(10); //匿名对象  特点：当前执行结束后，系统会立即回收掉匿名对象
    //注意事项： 不要利用拷贝构造函数，初始化匿名对象  编译器会认为Person (p3) ==== Person p3; 认为对象申明
    //Person(p2);

    //3、隐式调用
    Person p4 = 10; //相当于 Person p4 = Person(10)
    Person p5 = p4; //隐式调用拷贝构造
}