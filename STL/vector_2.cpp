//vector容器中存放自定义数据类型
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person{
    public:
        Person(string name, int age){
            this->mName = name;
            this->mAge = age;
        }
        string mName;
        int mAge;
};

void test1(){
    vector<Person> v;
    Person p1("aa", 10);
    Person p2("bb", 20);
    Person p3("cc", 30);

    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    for (vector<Person>::iterator itBegin = v.begin(); itBegin != v.end(); itBegin++){
        cout << itBegin->mName << " " << itBegin->mAge << endl;
    }
}

void test2(){
    vector<Person *> v;
    Person p1("aa", 10);
    Person p2("bb", 20);
    Person p3("cc", 30);

    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    for(vector<Person *>::iterator itBegin = v.begin(); itBegin != v.end(); itBegin++){
        cout << (*itBegin)->mName << " " <<(*itBegin)->mAge << endl;
        
    }

}

int main(){
    test2();
    return 0;
}