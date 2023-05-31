#include <iostream>
using namespace std;

//设置全局变量
int g_a = 10;
int g_b = 10;
const int c_g_a = 10;
const int c_g_b = 10;
int main(){
    //设置局部变量
    int a = 10;
    int b = 10;
    //设置静态变量
    static int s_a = 10;
    static int s_b = 10;
    //设置const修饰的局部变量
    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "a的地址" << &a << endl;
    cout << "b的地址" << &b << endl;
    cout << "静态b的地址" << &s_a << endl;
    cout << "静态b的地址" << &s_b << endl;
    cout << "全局a的地址" << &g_a << endl;
    cout << "全局b的地址" << &g_b << endl;
    //字符串常量
    cout << "字符串常量的地址" << &"hello world" << endl;
    //const修饰的变量
    //const修饰的全局变量，const修饰的局部变量
    cout << "全局常量a的地址" << &c_g_a << endl;
    cout << "全局常量b的地址" << &c_g_b << endl;
    //局部常量地址
    cout << "局部常量a的地址" << &c_l_a << endl;
    cout << "局部常量b的地址" << &c_l_b << endl;
    
       

    return 0;
}