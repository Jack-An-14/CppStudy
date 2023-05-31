//继承中构造和析构的顺序
//子类继承父类后，当创建子类对象，也会调用父类的构造函数
//问题：构造和析构顺序
#include <iostream>
using namespace std;
class Base{
    public:
        Base(){
            cout << "Base构造函数" << endl;
        }

        ~Base(){
            cout << "Base的析构函数" << endl;
        }
};

class Child : public Base{
    public:
        Child(){
            cout << "Child构造函数" << endl;
        }

        ~Child(){
            cout << "Child的析构函数" << endl;
        }
};

void test1(){
    Child c;
}
int main(){
    test1();
    return 0;
}

/*运行结果，类似栈的形式。先构造父类，在构造子类；先析构子类，在析构父类
Base构造函数
Child构造函数
Child的析构函数
Base的析构函数
*/