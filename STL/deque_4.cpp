//deque插入和删除
#include <iostream>
#include <deque>
using namespace std;
void printDeque(const deque<int> & d){
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test1(){
    deque<int> d1;

    //尾插
    d1.push_back(10);
    d1.push_back(20);

    //头插
    d1.push_front(1);
    d1.push_front(100);

    printDeque(d1);

    //尾删
    d1.pop_back();
    printDeque(d1);

    //头删
    d1.pop_front();
    printDeque(d1);
}

void test2(){
    deque<int> d1;

    //尾插
    d1.push_back(10);
    d1.push_back(20);

    //头插
    d1.push_front(1);
    d1.push_front(100);

    //insert的三个重载版本
    d1.insert(d1.begin(), 1000);
    printDeque(d1);

    d1.insert(d1.begin(), 2, 1);
    printDeque(d1);

    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);

    deque<int>::iterator it = d1.begin();
    it += 3;
    //删除第4个元素
    d1.erase(it);
    printDeque(d1);
    
    //区间删除
    d1.erase(d1.begin(), d1.end());
    printDeque(d1);
    //全部删除操作
    d2.clear();
}
int main(){
    // test1();
    test2();
    return 0;
}