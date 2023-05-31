#include <iostream>

using namespace std;

int main() {
    //1、定义指针
    int a = 10;
    //指针定义的语法: 数据类型* 变量名
    int* p;
    //让指针记录变量a的地址
    p = &a;

    cout << &a << endl;
    
    cout << p << endl;
    
    //2、使用指针
    //可以通过解引用，找到指针指向内存中的数据
    *p = 1000;
    cout << a << endl;
    return 0;
}