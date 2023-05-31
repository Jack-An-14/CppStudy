//set插入和删除
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
    set<int> s1;
    s1.insert(1);
    s1.insert(-1);
    s1.insert(2);
    s1.insert(9);
    printset(s1);
    //清空函数 clear()
    // s1.clear();
    // printset(s1);
    //erase删除指定迭代器的元素
    set<int>::iterator it = s1.erase(s1.begin());
    cout << *it << endl;    
    //erase删除指定元素
    s1.erase(9);
    printset(s1);
    //删除指定区间
    s1.erase(s1.begin(), s1.end());
    printset(s1);
}
int main(){
    test1();
    return 0;
}