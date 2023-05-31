//this指针
#include <iostream>
using namespace std;

class Person{
public:
    Person(int age){
        //this指针指向被调用的成员函数所属的对象
        this->age = age;
    }

    int age;

    //返回Person，会调用拷贝构造函数，会创建新的对象
    Person& PersonAddAge(Person & p){
        this->age += p.age;

        return *this;
    }
};

void test1(){
    Person p1(18);
    cout << p1.age << endl;
}

void test2() {
    Person p1(10);

    Person p2(11);
    //链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

    cout << p2.age << endl;

}
int main(){
    test2();
    return 0;
}