#include <iostream>
#include <list>
using namespace std;

//list排序自定义数据类型。满足按年龄升序排列。年龄相等时，按照身高将虚排列。
class Person{
    public:
        string name;
        int age;
        int height;
        Person(){}

        Person(string name, int age, int height){
            this->name = name;
            this->age = age;
            this->height = height;
        }
};
bool comp(Person p1, Person p2){
    if(p1.age < p2.age){
        return true;
    }
    else if(p1.age == p2.age){
        if(p1.height > p2.height){
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}
void printlist(const list<Person> & l){
    for (list<Person>::const_iterator it = l.begin(); it != l.end(); it++){
        cout << it->name << " " << it->age << " " << it->height << " ";
    }
    cout << endl;
}
void test1(){
    list<Person> l;
    l.push_back(Person("jack", 10, 120));
    l.push_back(Person("aack", 11, 130));
    l.push_back(Person("dack", 12, 100));
    l.push_back(Person("cack", 12, 170));

    printlist(l);
    l.sort(comp);
    printlist(l);
}
int main(){
    test1();
    return 0;
}