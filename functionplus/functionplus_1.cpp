//函数默认参数
#include <iostream>
using namespace std;

int func(int a, int b = 20, int c = 30){
    
    return a+b+c;
}

int main() {
    cout << func(10, 20, 30) << endl;
    cout << func(1) << endl;

    return 0;
}
