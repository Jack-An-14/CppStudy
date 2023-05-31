//赋值运算符重载
#include <iostream>
using namespace std;

class Person{
    public:
        int * m_age;

        Person(int age){
            m_age = new int(age);
        }
        ~Person(){
            if(m_age != NULL){
                delete m_age;
                m_age = NULL;
            }
        }
        Person& operator=(Person & p){
            //应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
            //释放内存
            if(m_age != NULL){
                delete m_age;
                m_age = NULL;
            }

            //深拷贝
            m_age = new int(*p.m_age);

            return *this;
        }
};

void test1() {
    Person p1(19);

    cout << *p1.m_age << endl;

    Person p2(20);
    cout << *p2.m_age << endl;

    p2 = p1;    //赋值操作
    //堆区内存重复释放，利用深拷贝解决浅拷贝问题

    Person p3(30);
    p3 = p2 = p1;
    cout << *p3.m_age << endl;
}
int main(){
    test1();
    return 0;
}