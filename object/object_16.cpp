//空指针调用成员函数
#include <iostream>
using namespace std;

class Person{
    public:
        void showClassName(){
            cout << "this is Person class" << endl;
        }

        void showPersonAge(){
            //报错原因是传入的指针为空
            if(this == NULL){
                return;
            }
            cout << "age = " << m_Age << endl;
        }

        int m_Age;
};

void test1(){
    Person * p = NULL;
    p->showClassName();
    p->showPersonAge(); //报错
}
int main() {
    test1();
    return 0;
}