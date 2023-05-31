//list数据存取操作
#include <iostream>
#include <list>
using namespace std;

//list容器只能在链表头和链表尾进行存取

void test1(){
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    cout << l1.front() << endl;
    cout << l1.back() << endl;
    //返回的是数据的引用，所以可以对数据进行修改
    l1.front() = 1000;
    cout << l1.front() << endl;
}

int main(){

    test1();
    return 0;
}