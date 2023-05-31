//内联函数
//算术仿函数
#include <iostream>
//引入头文件functional
#include <functional>

//negate一元仿函数，取反


using namespace std;
void test1(){
    negate<int> n;
    cout << n(50) << endl;
}

//plus二元仿函数，加法
void test2(){
    plus<int> p;
    cout << p(10, 20) << endl;

//modulus取模
    modulus<int> m;
    cout << m(10, 3) << endl;

}

int main(){
    test1();
    test2();
    return 0;
}