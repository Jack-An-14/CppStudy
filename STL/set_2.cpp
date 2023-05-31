#include <set>
#include <iostream>
using namespace std;

void printset(const set<int> & s){
    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test1(){
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(0);
    //判空函数
    if(s.empty()){
        cout << "空" << endl;
    }
    else {
        cout << "不为空" << endl;
        //size函数
        cout << "size = " << s.size() << endl;
    }

    set<int> s2;
    s2.insert(1);
    s2.insert(3);
    s2.insert(9);

    printset(s);
    printset(s2);
    //交换
    s.swap(s2);
    printset(s);
    printset(s2);
}
int main(){
    test1();
    return 0;
}