#include <iostream>
#include <string>
using namespace std;
//类模版的分文件编写
template <class T1, class T2>
class Person{
    public:
        T1 mName;
        T2 mAge;
        Person(T1 name, T2 age);

        void showPerson();
};
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age){
    this->mName = name;
    this->mAge = age;
}

template <class T1, class T2>
void Person<T1, T2>::showPerson(){
    cout << mName << " "  << mAge << endl;
}

int main(){

    return 0;
}