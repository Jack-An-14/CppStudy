//set存放自定义数据类型，完成排序操作
#include <iostream>
#include <set>
#include <string>
using namespace std;
class Person{
    public:
        string mName;
        int mAge;
        Person(string name, int age){
            mName = name;
            mAge = age;
        }

};

class MyCompare{
    public:
    //降序排列
    bool operator()(const Person & p1, const Person & p2){
        return p1.mAge > p2.mAge;
    }
};

void test1(){
    //自定义数据类型，都会指定排序规则
    set<Person, MyCompare> s1;
    s1.insert(Person("liubei", 24));
    s1.insert(Person("gunayu", 234));
    s1.insert(Person("li", 34));
    s1.insert(Person("lii", 21));

    for(set<Person, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++){
        cout << it->mName << " " << it->mAge << endl;
    }
}
int main(){
    test1();
    return 0;
}