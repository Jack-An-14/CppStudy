//string字符存取
//[]方式取字符
//at函数访问字符
#include <iostream>
using namespace std;

void test1(){
    string str = "hello";
    cout << sizeof(str) << endl;
    for (int i = 0; i < str.size(); i++){
        cout << str[i] << endl;
    }

    for (int i = 0; i < str.size(); i++){
        cout << str.at(i) << endl;
    }

    //修改单个字符
    str[0] = 'x';
    cout << str << endl;
    str.at(1) = 'z';
    cout << str << endl; 
}
int main(){
    test1();
    return 0;
}