#pragma once
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