//string 查找和替换
//查找：查找指定字符串是否存在
//替换：在指定的位置替换字符
#include <iostream>
#include <string>

using namespace std;

void test1(){
    string str1 = "abcdefgde";
    //返回字串的开始位置，查不到返回-1
    int pos = str1.find("de");
    if(pos == -1){
        cout << "没有查到字串" << endl;
    }
    else {
        cout << pos << endl;
    }
    //rfind 和 find 的区别
    //rfind从右往左查找
    //find从左往右查找
    pos = str1.rfind("de");
    cout << pos << endl;
    
}

void test2(){
    string str1 = "abcdefg";
    //第一个参数：起始位置， 第二个参数：替换的字符数， 第三个参数：替换的字符串
    //从1位置起3个字符替换成1111
    str1.replace(1, 3, "1111");
    cout << str1 << endl;
}

int main(){
    // test1()
    test2();
    return 0;
}