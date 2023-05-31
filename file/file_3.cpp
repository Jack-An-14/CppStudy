//二进制文件读写操作
#include <iostream>
#include <fstream>
using namespace std;
//二进制写文件

class Person{
    public:
        char mName[64];//姓名
        int mAge;//年龄
};

void test(){
    ofstream ofs;
    ofs.open("person.txt", ios::out | ios::binary);

    Person p = {"张三", 18};
    ofs.write((const char *) &p, sizeof(Person));

    ofs.close();
}
int main(){
    test();
    return 0;
}