//二进制读文件
#include <iostream>
#include <fstream>
using namespace std;

class Person{
    public:
        char mName[64];//姓名
        int mAge;//年龄
};

void test(){
    ifstream ifs;
    ifs.open("person.txt", ios::in | ios::binary);

    if(!ifs.is_open()){
        cout << "读文件失败" << endl;
    }

    Person p;
    ifs.read((char *) & p, sizeof(Person));
    cout << p.mName << endl;
    cout << p.mAge << endl;
    ifs.close();
}
int main(){
    test();
    return 0;
}