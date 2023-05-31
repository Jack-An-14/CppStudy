//函数重载注意事项
//1、引用作为重载条件
//2、函数重载碰到函数默认参数
#include <iostream>
using namespace std;

//引用作为函数重载的条件
void func(int &a){
    cout << "func(int &a)调用" << endl;
}

void func(const int &a){
    cout << "func(const int &a)调用" << endl;
}

//2函数重载遇到默认参数
void func2(int a, int b = 10){
    cout << "func2(int a, int b = 10)" << endl;
}

void func2(int a){
    cout  << "func2(int a)" << endl;
}
int main(){
    int a = 20;
    func(a);
    func(10);
    // func2(10);

    return 0;
}
