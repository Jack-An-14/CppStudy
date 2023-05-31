//类模版中成员函数的创建时机
#include <iostream>
using namespace std;

class Person1{
    public:
        void showPerson1(){
            cout << "Person1" << endl;
        }
};


class Person2{
    public:
        void showPerson2(){
            cout << "Person2" << endl;
        }
};

template<class T>
class Mclass{
    public:
        T obj;
        //类模版中的成员函数,不是一开始就创建出来的，因为不能确定obj的类型
        void func1(){
            //只有调用的时候，才会创建T类型的obj
            obj.showPerson1();
        }

        void func2(){
            obj.showPerson2();
        }
};

void test(){
    Mclass<Person1> m;
    m.func1();
    m.func2();
}
int main(){
    test();
    return 0;
}