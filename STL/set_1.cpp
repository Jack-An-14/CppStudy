//set容器构造函数和赋值操作
#include <iostream>
#include <set>
using namespace std;

void printset(const set<int> & s){
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test1(){
    //默认构造
    set<int> s1;
    //通过insert函数插入元素
    s1.insert(1);
    s1.insert(2);
    s1.insert(3);
    s1.insert(4);
    s1.insert(6);
    s1.insert(0);

    //遍历容器
    printset(s1);
    //operator=赋值
    set<int> s2 = s1;
    printset(s2);

    //拷贝构造
    set<int> s3(s1);
    printset(s1);
}
int main(){
    test1();
    return 0;
}