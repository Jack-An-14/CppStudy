//list容器的反转和排序
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void printlist(const list<int> & l){
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

bool Comp(int v1, int v2){
    //降序排列， 让第一个数>第二个数

    return v1 > v2;
}

void test1(){
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    
    //成员函数反转
    l1.reverse();
    printlist(l1);

    //不支持随机访问的迭代器是不能使用标准排序算法的
    //list的迭代器不支持随机访问
    //不支持随机访问的容器，内部会提供一些对应的算法
    // sort(l1.begin(), l1.end());
    
    l1.sort(); //存在默认的排序规则为升序，从小到大
    printlist(l1);
    //函数重载，构建比较函数
    l1.sort(Comp);
    printlist(l1);
    

}

int main(){
    test1();
    return 0;
}