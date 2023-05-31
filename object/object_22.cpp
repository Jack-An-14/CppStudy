//左移运算符
#include <iostream>
using namespace std;
class Person{
    friend ostream& operator<< (ostream & out , Person & p);
    public:
        Person(){
            m_A = m_B = 10;
        }
    private:
        int m_A;
        int m_B;
};
//通常不使用成员函数去重载左移运算符
ostream& operator<< (ostream & out , Person & p){
    out << p.m_A << " " << p.m_B;
    return out;
} //本质:operator<< (cout, p)  简化 cout << p
void test1(){
    Person p1;

    cout << p1 << "add somethis" << endl;
}
int main() {
    test1();
    return 0;
}