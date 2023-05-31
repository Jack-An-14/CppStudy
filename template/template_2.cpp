#include <iostream>
using namespace std;

//函数模版注意事项
//1、自动类型推导，必须推导出一致的数据类型T
//2、模版必须确定T地数据类型，才可以使用

template<class T> //typename可以替换成class
void mswap(T & a, T & b){
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void func(){
    cout << "func" << endl;
}
void test(){
    int a = 10;
    int b = 20;

    char c = 'c';
    
    // mswap(a, c); 错误 推导出不一定的数据类型

    // func(); 没有指定函数模版类型
    //只能显示指定T
    func<int>();
}

int main(){
    test();
    return 0;
}