//find算法 查找元素
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//1、查找内置数据类型
void test1(){
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //无论是否找到，都会返回迭代器
    vector<int>::iterator it  = find(v.begin(), v.end(), 50);
    if(it == v.end()){
        cout << "没找到" << endl;
    }
    else {
        cout << *it << endl;
    }

}

class Person{
    public:
        Person(string name, int age){
            this->mName = name;
            this->mAge = age;
        }
        string mName;
        int mAge;
        
        //重载==，用引用必须使用const修饰，繁殖修改底层代码。不用引用，不加const。因为是拷贝出来的，不会修改
        bool operator== (const Person & p2){
            return this->mName == p2.mName && this->mAge == p2.mAge;
        }
};

//2、查找自定义数据类型,查找的时候，需要重载==
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

    vector<Person>::iterator it = find(v.begin(), v.end(), Person("aaa", 10000));
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