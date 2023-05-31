//string字符串比较
//比较方式：按字符的ASCII码对比。= 返回 0， > 返回 1， < 返回 -1
#include <iostream>
using namespace std;


void test1(){
    string str1 = "aello";
    string str2 = "hello";
    int flag = 0;
    if((flag = str1.compare(str2)) == 0){
        cout << "equal" << endl;
    }
    else {
        cout << flag << endl;
    }
}
int main(){
    test1();
    return 0;
}