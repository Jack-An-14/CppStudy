//string字符串拼接
//1、 +=
//2、 append
#include <iostream>
#include <string>
using namespace std;

void test1(){

    //1、 +=
    string str1 = "wo ";
    str1 += "ai wan you xi";
    cout << str1 << endl;

    str1 += 'C';
    cout << str1 << endl;

    string str2 = "nima";
    str1 += str2;
    cout << str1 << endl;

    //2、append函数
    string str3 = "love ";
    str3.append("me");
    cout << str3 << endl;
    //拼接前n个字符
    str3.append(" game abcde", 4);
    cout << str3 << endl;

    //拼接str2
    str3.append(str2);
    cout << str3 << endl;

    //从5位置截3个字符的字串拼接
    str3.append("spoakfjoaspdofj", 5, 3);
    cout << str3 << endl;
}
int main(){
    test1();
    return 0;
}