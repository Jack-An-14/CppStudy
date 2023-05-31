//查找算法 find_if
//按值查找元素，找到返回指定位置的迭代器，找不到返回尾部迭代器
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Greater{
    public:
        bool operator()(int val){
            return val > 5;
        }
};

class Person{
    public:
        Person(string name, int age){
            this->mName = name;
            this->mAge = age;
        }
        string mName;
        int mAge;
};

class MyCompare{
    public:
        bool operator()(Person & p){
            return p.mAge > 20;
        }
};

//1、内置数据类型
void test1(){
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    vector<int>::iterator it = find_if(v.begin(), v.end(), Greater());
    if(it == v.end()){
        cout << "没找到" << endl;
    }
    else {
        cout << *it << endl;
    }
}
//2、自定义数据类型
void test2(){
    vector<Person> v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);

    vector<Person>::iterator it = find_if(v.begin(), v.end(), MyCompare());
    if(it == v.end()){
        cout << "没找到" << endl;
    }
    else {
        cout << it->mName << " " << it->mAge << endl;
    }
}

int main(){
    test1();
    test2();
    return 0;
}