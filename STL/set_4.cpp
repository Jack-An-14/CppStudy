//set容器的查找和统计
#include <iostream>
#include <set>
#include <string>
using namespace std;

void test1(){
    multiset<int> s1;
    s1.insert(1);
    s1.insert(2);
    s1.insert(13);
    s1.insert(14);
    s1.insert(1);
    
    //统计元素个数
    cout << s1.count(1) << endl;
    //find函数返回查找元素的迭代器
    set<int>::iterator it = s1.find(200);
    cout << *it << endl;
    bool rs = (it == s1.end());
    cout << rs << endl;
}

int main(){
    test1();
    return 0;
}