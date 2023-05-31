//初始化列表语法
#include <iostream>
using namespace std;
class Person{
public:
    int m_A;
    int m_B;
    int m_C;

    // Person(int a, int b, int c){
    //     m_A = a;
    //     m_B = b;
    //     m_C = c;
    // }

    Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c){
        
    }
};

int main(){
    Person p(30,20,10);
    return 0;
}