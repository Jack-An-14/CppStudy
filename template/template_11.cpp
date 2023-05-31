//类模版与继承
#include <iostream>
using namespace std;
template <class T>
class Base{
    public:
        T m;
};

// class Son : public Base  //错误，必须要知道父类中T的数据类型，子类才能继承
//声明T的类型
class Son : public Base<int>{

};

void test1(){
    Son s1;
}
//如果想要灵活指定T的类型,类型对应传递
template<class T1, class T2>
class Son2 : public Base<T2>{
    public:
        T1 obj;
        Son2(){
            cout << typeid(T1).name() << endl;
            cout << typeid(T2).name() << endl;
        }
};

void test2(){
    Son2<int, char> s2;
}
int main(){
    // test1();
    test2();
    return 0;
}