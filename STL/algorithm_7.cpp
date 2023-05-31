//count统计元素个数
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//1、统计内置数据类型
void test1(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(40);
    cout << count(v.begin(), v.end(), 40) <<endl;
}
//2、统计自定义数据类型
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
            // return this->mName == p2.mName && this->mAge == p2.mAge;
            return this->mAge == p2.mAge;
        }
};
void test2(){
    vector<Person> v;
    v.push_back(Person("aa", 10));
    v.push_back(Person("bb", 10));
    v.push_back(Person("aa", 10));
    v.push_back(Person("aa", 10));

    //需要重载==
    //查找年龄相等的人数
    cout << count(v.begin(), v.end(), Person("aa", 10));
}
int main(){
    test1();
    test2();
    return 0;
}