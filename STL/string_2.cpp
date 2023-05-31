//string的赋值操作
//1、operator =
//2、assgin（）函数
#include <iostream>
#include <string>
using namespace std;

void test1(){
    string str1;
    str1 = "hello world";
    cout << str1 << endl;

    string str2 = str1;
    cout << str2 << endl;

    string str3;
    str3 = 'a';
    cout << str3 << endl;

    //assign方式赋值
    string str4;
    str4.assign("hello C++");
    cout << str4 << endl;

    //前n个字符，赋值过来
    string str5;
    str5.assign("hello c++", 5);
    cout << str5 << endl;

    string str6;
    str6.assign(7, 'a');
    cout << str6 << endl;
}

int main(){

    test1();

    return 0;
}