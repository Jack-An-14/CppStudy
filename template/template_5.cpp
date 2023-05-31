#include <iostream>
using namespace std;

void mprint(int a, int b){
    cout << "普通函数" << endl;
}

template<class T>
void mprint(T a, T b){
    cout << "函数模版调用" << endl;
}


template<class T>
void mprint(T a, T b, T c){
    cout << "重载函数模版调用" << endl;
}

void test(){
    int a = 0;
    mprint(a, a); //普通函数和模版函数都可以时，优先调用普通函数
    mprint<>(a, a);//通过空模版参数列表强制调用模版函数
    mprint(a, a, a);//函数模版可以发生函数重载

    //如果函数模版产生更好的匹配，优先调用函数模版
    char c1 = 'a';
    char c2 = 'b';
    mprint(c1, c2);//调用函数模版，因为如果调用普通函数需要隐式类型转换，模版函数只需要推导一致的参数类型即可，模版函数更匹配

}
int main(){
    test();
    return 0;
}