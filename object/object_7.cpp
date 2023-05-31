//拷贝构造函数调用的三种情况
//使用一个已经创建完毕的对象来初始化另一个新对象
//值传递的方式给函数参数传值
//以值方式返回局部对象

#include <iostream>

using namespace std;
class Person{
public:
    Person(){
        m_age = 10;
        cout << "Person的无参构造函数" << endl;
    }

    Person(int a){
        m_age = a;
        cout << "Person的有参构造函数" << endl;
    }

    Person(const Person & p){
        m_age = p.m_age;
        cout << "Person的拷贝构造函数" << endl;
    }

    ~Person(){
        cout << "Person的析构函数" << endl;
    }
    
    int m_age;
};

void test01(){
    Person p1(20);
    Person p2(p1);
}

void doWork(Person p){

}

void test02(){
    Person p;
    doWork(p);//这里会调用拷贝构造函数，但是只拷贝值
}

Person doWork2(){
    Person p1;
    return p1;  //根据p1返回新的对象
}

void test03(){
    Person p = doWork2();
}

int main(){
    test03();


    return 0;
}