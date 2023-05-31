//读文件
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test1(){
    
    //创建流对象
    ifstream ifs;
    //打开文件并且判断文件是否打开成功
    ifs.open("test.txt", ios::in);

    if(!ifs.is_open()){
        cout << "文件打开失败" << endl;

        return ;
    }
    //读数据

    //第一种
    char buf[1024] = {0};
    while (ifs >> buf){
        cout << buf <<endl;
    }
    
    //第二种
    char buf2[1024] = {0};
    while (ifs.getline(buf2, sizeof(buf2))){
        cout << buf2 << endl;
    }
    

    

    //第三种
    string buf3;
    while (getline(ifs, buf3)){
        cout << buf3 << endl;
    }

    //第四种
    //EOF文件尾
    char c;
    while ((c = ifs.get()) != EOF){
        cout << c;
    }
    //关闭文件
    ifs.close();
}

int main(){
    test1();
    return 0;
}