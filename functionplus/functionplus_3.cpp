//函数重载
//函数名相同，可以提高函数复用性
#include <iostream>

using namespace std;

void func(int a, int b){
    cout << "func(int a, int b)" << endl;
}

void func(int a, string b){
    cout << "func(int a, string b)" << endl;
}
int main(){
    func(10, "20");

    return 0;
}