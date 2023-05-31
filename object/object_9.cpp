//深拷贝和浅拷贝
#include <iostream>
using namespace std;
class Person{
public:
    Person(){
        m_age = 10;
        cout << "Person的无参构造函数" << endl;
    }

    Person(int a, int height){
        m_age = a;
        m_height = new int(height);
        cout << "Person的有参构造函数" << endl;
    }

    //自己实现深拷贝，解决浅拷贝的问题
    Person(const Person& p){
        cout << "拷贝构造函数" << endl;
        m_age = p.m_age;
        m_height = new int(*p.m_height);
    }

    ~Person(){
        //析构代码，将堆区开辟数据释放掉
        cout << "Person的析构函数" << endl;
        if(m_height != NULL){
            delete m_height;
            m_height = NULL;
        }
        delete m_height;
    }
    
    int m_age;
    int * m_height;
};

void test1(){
    Person p1(18, 160);
    cout << p1.m_age << " " << *p1.m_height << endl;
    Person p2(p1);
    cout << p2.m_age << " " << *p2.m_height << endl;
}
int main(){
    test1();
    return 0;
}