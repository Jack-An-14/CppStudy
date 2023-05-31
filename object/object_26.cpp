//关系运算符重载
#include <iostream>
using namespace std;
class Person{
    public:
        string m_Name;
        int m_Age;

        Person(string name, int age){
            m_Name = name;
            m_Age = age;
        }

        bool operator==(Person & p) {
            return this->m_Age == p.m_Age && this->m_Name == p.m_Name;
        }

        bool operator!=(Person & p){
            return this->m_Age != p.m_Age || this->m_Name != p.m_Name;
        }
};

void test1(){

    Person p1("Tom", 18);
    Person p2("Tom", 18);

    if(p1 == p2){
        cout << "equal" << endl;
    }else {
        cout << "inequal" << endl;
    }

    if(p1 != p2){
        cout << "inequal" << endl;
    }else {
        cout << "equal" << endl;
    }
}
int main() {
    test1();
    return 0;
}