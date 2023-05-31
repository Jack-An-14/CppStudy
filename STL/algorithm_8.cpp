//count_if 按条件统计元素个数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//1、内置数据类型
class Greater20{
    public:
        bool operator()(int val){
            return val > 20;
        }
};
void test1(){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    int num = count_if(v.begin(), v.end(), Greater20());
    cout << num << endl;

}
//2、自定义数据类型
class Person{
    public:
        Person(string name, int age){
            this->mName = name;
            this->mAge = age;
        }
        string mName;
        int mAge;
        
        //重载==，用引用必须使用const修饰，防止修改底层代码。不用引用，不加const。因为是拷贝出来的，不会修改
        // bool operator== (const Person & p2){
        //     return this->mName == p2.mName && this->mAge == p2.mAge;
        // }
};

class Mycom{
    public:
        bool operator()(const Person & p){
            return p.mAge == 10;
        }
};
void test2(){
    vector<Person> v;
    v.push_back(Person("aa", 10));
    v.push_back(Person("bb", 10));
    v.push_back(Person("cc", 10));
    v.push_back(Person("dd", 10));
    v.push_back(Person("ff", 10));
    v.push_back(Person("ee", 10));

    int num = count_if(v.begin(), v.end(), Mycom());
    cout << num << endl;
}
int main(){
    test1();
    test2();
    return 0;
}