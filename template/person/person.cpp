#include "person.h"
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age){
    this->mName = name;
    this->mAge = age;
}

template <class T1, class T2>
void Person<T1, T2>::showPerson(){
    cout << mName << " "  << mAge << endl;
}