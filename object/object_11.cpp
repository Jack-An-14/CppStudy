#include <iostream>
#include <string>
using namespace std;
//类对象作为类成员

//问题：构造函数析构函数顺序:析构函数顺序与构造函数相反
class Phone{
    public:
        string p_Name;

        Phone(string name){
            p_Name = name;
            cout << "手机构造函数调用" <<endl;
        }
        ~Phone(){
            cout << "手机的析构函数" << endl;
        }
};
class Person{
public:
    //姓名
    string m_Name;
    //手机
    Phone p;

    Person(string name, string pName):m_Name(name), p(pName){
        cout << "人的构造函数调用" << endl;
    }
    ~Person(){
        cout << "人的析构函数" <<endl;
    }
};

void test1(){
    Person p("张三", "苹果MAX");

    cout << p.m_Name << "拿着" << p.p.p_Name << endl;
}

int main(){
    test1();

    return 0;
}