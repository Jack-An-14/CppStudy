//deque排序
#include <iostream>
#include <deque>
//算法包含的头文件
#include <algorithm>
using namespace std;

void printDeque(const deque<int> & d){
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test1(){
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(1);
    d1.push_back(2);
    printDeque(d1);
    //填入区间迭代器
    deque<int>::iterator it = d1.end();
    it--;
    sort(d1.begin(), it);
    printDeque(d1);
    
}

int main(){
    test1();
    return 0;
}