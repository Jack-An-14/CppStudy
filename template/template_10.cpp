//类模版对象做函数参数
#include <iostream>
#include <string>

using namespace std;
template <class T1, class T2>
class Person{
    public:
        T1 mName;
        T2 mAge;
        Person(T1 name, T2 age){
            mName = name;
            mAge = age;
        }

        void showPerson(){
            cout << mName << " " << mAge << endl;
        }
};

//类模版对象做函数参数.最常用
//1、指定传入类型.类模版对象的类型作为函数形参，并声明为引用的方式
void printPerson1(Person<string, int> & p){
    p.showPerson();
}
void test1(){
    Person<string, int> p("sunwukong", 100);
    printPerson1(p);
}
//2、参数模版化
template<class T1, class T2>
void printPerson2(Person<T1, T2> & p){
    p.showPerson();
    //查看推导出类型的方法代码
    cout << typeid(T1).name() << endl;
    cout << typeid(T2).name() << endl;
}
void test2(){
    Person<string, int> p("zhubajie", 90);
    printPerson2(p);

}
//3、整个类模版化
template<class T>
void printPerson3(T & p){
    p.showPerson();
}
void test3(){
    Person<string, int> p("tangseng", 30);
    printPerson3(p);
}
int main(){
    // test1();

    // test2();
    test3();
    return 0;
}