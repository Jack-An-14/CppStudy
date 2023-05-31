//对象的初始化和清理
//1、构造函数 初始化
//2、析构函数
#include <iostream>
using namespace std;
class Person{
public:
    Person(){
        cout << "构造函数调用" << endl;
    }
    
    ~Person(){
        cout << "析构函数调用" << endl;
    }

};
int main(){
    Person p;

    return 0;
} 