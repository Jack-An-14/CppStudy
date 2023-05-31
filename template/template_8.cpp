//类模版和函数模版的区别
#include <iostream>
#include <string>
using namespace std;

template<class NameType, class AgeType = int >  //这里设置了类模版的参数类型默认值
class Person{
    public:
        Person(NameType name, AgeType age){
            this->mName = name;
            this->mAge = age;
        }
        NameType mName;
        AgeType mAge;

        void showPerson(){
            cout << mName << " " << mAge << endl;
        }
};
//1、类模版没有自动类型推导使用方式
void test1(){
    // Person p("sunwukong", 999);  无法使用，因为类模版不能使用自动类型推导
    Person <string, int> p ("sunwukk", 99);

    p.showPerson();
}
//2、类模版在模版参数列表中可以有默认参数,函数模版不能使用默认参数
void test2(){
    Person<string> p("zhubajie", 10);
}
int main(){
    test1();
    return 0;
}