//普通函数与函数模版区别
//1、普通函数调用可以发生隐式类型转换
//2、函数模版 用自动类型推导，不可以发生隐式类型转换
//3、函数模版 用现实指定类型，可以发生隐式类型转换
#include <iostream>
using namespace std;

int myadd01(int a, int b){
    return a + b;
}

//函数模版
template<class T>
T myadd02(T a, T b){
    return a + b;
}
void test(){
    int a = 10;
    int b = 20;
    char c = 'c';
    cout << myadd01(a, c) << endl;  //把字符型隐式的转换为整型

    //自动推导
    cout << myadd02(a, b) << endl;

    // cout << myadd02(a, c) << endl;  没法推导成一致参数类型

    //显示指定类型,可以发生隐式类型转换
    cout << myadd02<int>(a, c) << endl;
}

int main(){

    test();
}