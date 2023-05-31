#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Personl{
    public:
        T1 mName;
        T2 mAge;
        //类内写函数声明，类外写实现
        Personl(T1 name, T2 age);

        void showPersonl();
        //     cout << mName << " " << mAge << endl;
        // }    
};
template<class T1, class T2>
Personl<T1, T2>::Personl(T1 name, T2 age){
    this->mName = name;
    this->mAge = age;
}
//成员函数的类外实现，要变成类模版的实现
template<class T1, class T2>
void Personl<T1, T2>::showPersonl(){
    cout << mName << " " << mAge << endl;
}

void test(){
    Personl<string, int> p("maojie", 18);
    p.showPersonl();
}
int main(){
    test();
    return 0;
}