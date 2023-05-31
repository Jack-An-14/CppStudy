//函数模版的局限性
//给特定类型提供具体化的模版
#include <iostream>
#include <string>
using namespace std;
class Person{
    public:
        string mname;
        int mage;
        Person(string name, int age){
            mname = name;
            mage = age;
        }
};
template<class T>
bool mCompare(T & a, T & b){
    if (a == b){
        return true;
    }
    else {
        return false;
    }
}

//具体化操作
//利用具体化Person地版本实现代码，具体化优先调用
template<> bool mCompare(Person & a, Person & b){
    if(a.mname == b.mname && a.mage == b.mage){
        return true;
    }
    else {
        return false;
    }
}

void test(){

    int a = 10; 
    int b = 20;

    bool ret = mCompare(a, b);
    if(ret){
        cout << "=" << endl;
    }else {
        cout << "!=" << endl;
    }
}

void test2(){
    Person p1("Tom", 10);
    Person p2("Tom", 10);

    bool ret = mCompare(p1, p2);
    if(ret){
        cout << "="<< endl;
    }
    else {
        cout << "!=" << endl;
    }
}
int main(){
    // test();
    test2();
    return 0;
}