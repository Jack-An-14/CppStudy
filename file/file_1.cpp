#include <iostream>
#include <fstream>
using namespace std;

//文本文件 写文件
void test1(){
    //创建流对象
    ofstream ofs;

    ofs.open("test.txt", ios::out|ios::trunc);

    ofs << "hello world" << endl;
    ofs << "nihao sb" << endl;

    ofs.close();
}

int main(){

    test1();
    return 0;
}