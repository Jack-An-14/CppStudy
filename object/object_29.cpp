//继承方式
#include <iostream>
using namespace std;
class A{
    public:
        int a;
    protected:
        int b;
    private:
        int c;
};

//protected 子类可以访问父类的保护内容
//公共继承
class Son1 : public A{
    public:
        void func(){
            cout << a << b << c << endl;
        }
};

//保护继承
class Son2 : protected A{
    public:
        void func(){
            cout << a << b << c << endl;
        }
};

//私有继承
class Son3 : private A{
    public:
        void func(){
            cout << a << b << c << endl;
        }
};
void test1(){
    Son1 s1;
    s1.a = 10;
    s1.b = 10;//在Son1中为保护权限，类外无法访问

    Son2 s2;
    s2.a = 10;//在Son2中为保权限，类外无法访问

    Son3 s3;
    s3.a = 10;//在Son3中为私有权限，类外无法访问
}
int main() {

    return 0;
}