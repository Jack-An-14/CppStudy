//继承中的对象模型
//问题：从父类继承过来的成员，哪些属于子类对象中
#include <iostream>
using namespace std;
class Base{
    public:
        int m_A;  
    protected:
        int m_B;
    private:
        int m_C;
};

class Son : public Base{
    public:
        int m_D;
};

void test1(){
    //Son为16，说明所有的属性都继承了下来
    //父类中所有的非静态成员都会被继承下来。私有成员被编译器隐藏
    cout << sizeof(Son) << endl;
}
int main() {
    test1();
    return 0;
}