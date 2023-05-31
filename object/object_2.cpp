//关于权限问题
//类的访问权限有三种，分别为public、private、protected
#include <iostream>

using namespace std;
class Person{
    public:
        string name;
    private:
        int password;
        void func(int pwd){
            this->password = pwd;
        }
    protected:
        int number;
};
int main() {
    Person p;
    p.number = 10;
    p.func();
    return 0;
}