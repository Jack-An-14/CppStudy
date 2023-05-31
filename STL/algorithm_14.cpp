//replace
//将容器内指定范围的旧元素修改为新元素
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class MyPrint{
    public:
        void operator()(int val){
            cout << val << " ";
        }
};
void test1(){
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }

    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    //内置数据类型替换
    replace(v.begin(), v.end(), 1, 30);
    for_each(v.begin(), v.end(), MyPrint());
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
            // return this->mName == p2.mName && this->mAge == p2.mAge;
            return this->mAge == p2.mAge;
        }
};

void myprint(const Person & p){
    cout << p.mName << " " << p.mAge << endl;
}
void test2(){
    vector<Person> v;
    v.push_back(Person("aaa", 100));
    v.push_back(Person("aaa", 100));
    v.push_back(Person("aaa", 100));
    v.push_back(Person("aaa", 100));
    v.push_back(Person("aaa", 100));
    Person p1 ("aaa", 100);
    replace(v.begin(), v.end(), p1, Person("bbb", 120));

    for_each(v.begin(), v.end(), myprint);
}
int main(){
    test1();
    test2();
    return 0;
}