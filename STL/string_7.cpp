//string 插入和删除
#include <iostream>
#include <string>

using namespace std;
void test1(){
    string str = "hello";
    //插入,在1处插入字符串
    str.insert(1, "javc");
    cout << str << endl;

    //erase删除，从1位置起删除4个字符
    str.erase(1, 4);
    cout << str << endl;
    
}

int main(){
    test1();
    return 0;
}