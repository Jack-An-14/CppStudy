//set和multiset的区别
#include <iostream>
#include <set>
using namespace std;

void test1(){
    set<int> s1;
    s1.insert(10);
    //set无法插入重复数据
    //set的insert函数返回的是pair<iterator, bool>类型的数据
    pair<set<int>::iterator, bool> ret = s1.insert(10);

    if(ret.second){
        cout << "插入成功" << endl;
    }
    else {
        cout << "插入失败" << endl;
    }

    multiset<int> mset;
    mset.insert(10);
    //multiset的插入函数返回的是迭代器
    multiset<int>::iterator it = mset.insert(10);

    for (multiset<int>::iterator it = mset.begin(); it != mset.end(); it++){
        cout << *it << endl;
    }
}
int main(){
    test1();
    return 0;
}