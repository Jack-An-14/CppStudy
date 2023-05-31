//类模版
#include <iostream>
#include <string>
using namespace std;
template<class NameType, class AgeType>
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

void test(){
    //尖括号里是模版参数列表
    Person<string, int> p1("sunwukong", 999);
    p1.showPerson();
}
int main(){
    test();
    return 0;
}