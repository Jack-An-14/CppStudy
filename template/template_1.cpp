//函数模版
#include <iostream>
using namespace std;


template <typename T>   //申明一个模版，告诉编译器T不报错
void mswap(T & a, T & b){
    T temp = a;
    a = b;
    b = temp;
}

void test(){
    int a = 1;
    int b = 0;
    //两种使用模版方式
    //1、自动推导数据类型
    mswap(a, b);
    //2、显示指定类型
    mswap<int>(a, b);

    cout << a << " " << b << endl;
}


int main(){
    test();
    return 0;
}