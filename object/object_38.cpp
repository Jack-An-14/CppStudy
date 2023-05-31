//虚析构和纯虚析构
//问题：多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

//解决方式：将父类中的析构函数改为虚析构或者纯虚析构
#include <iostream>
#include <string>
using namespace std;
class Animal{
    public:
        //纯虚函数
        virtual void speak() = 0;
        Animal(){
            cout << "Animal构造函数调用" << endl;
        }


        //利用虚析构，可以解决父类指针释放子类对象，释放不干净的问题
        // virtual ~Animal(){
        //     cout << "Animal的析构函数调用" << endl;
        // }


        //纯虚析构，需要声明也需要实现
        virtual ~Animal() = 0;
        //有了纯虚析构后，这个类也属于抽象类，无法实例化对象
};

//纯虚析构函数实现
Animal::~Animal(){
    cout << "Animal的纯虚析构函数调用" << endl;
}

class Cat : public Animal{
    public:

        Cat(string name){
            mName = new string(name);
            cout << "Cat构造函数调用" << endl;
        }
        void speak(){
            cout << *mName <<" cat speak" << endl;
        }

        string * mName;

        ~Cat(){
            if(mName != NULL){
                delete mName;
            }
            mName = NULL;
            cout << "Cat析构函数调用" << endl;
        }
};

void test1(){
    Animal * a = new Cat("Tom");
    a->speak();
    //父类指针在析构的时候，不会调用子类中析构函数，导致子类如果有堆区属性，出现内存泄漏
    delete a;
}
int main(){
    test1();
    return 0;
}