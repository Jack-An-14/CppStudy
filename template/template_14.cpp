//类模版与友元
//掌握类模版配合友元函数的类内和类外实现
#include <iostream>
#include <string>
using namespace std;
//提前让编译器知道类的存在
template<class T1, class T2>
class Person;

template<class T1, class T2>
void printPerson2(Person<T1, T2> p){
    cout << p.mName << " "  << p.mAge << endl;
};

template <class T1, class T2>
class Person{
    //全局函数，打印Person信息 类内实现
    friend void printPerson(Person<T1, T2> p){
        cout << p.mName << " "  << p.mAge << endl;
    }
    
    //加空模版参数列表
    //如果全局函数是类外实现，需要让编译器提前知道这个函数的存在
    friend void printPerson2<>(Person<T1, T2> p);

    public: 
        Person(T1 name, T2 age){
            this->mName = name;
            this->mAge = age;
        }

        void showPerson(){
            cout << mName << " "  << mAge << endl;
        }
    private:
        T1 mName;
        T2 mAge;
};

//1、全局函数在类内实现
void test1(){
    Person<string, int> p("tom", 21);
    printPerson(p);
}

//2、全局函数类外实现


void test2(){
    Person<string, int> p("tom", 21);
    printPerson2(p);
}
int main(){
    test2();
    return 0;
}