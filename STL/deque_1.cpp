//deque容器构造
#include <iostream>
#include <deque>
using namespace std;

// 防止内容修改，参数设置const
void printDeque(const deque<int> & d){
    //迭代器设置为const的
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it ++){
        cout << *it << " ";
    }
    cout << endl;
}
void test1(){
    //默认构造
    deque<int> d1;
    for (int i = 0; i < 10; i++){
        d1.push_back(i);
    }
    printDeque(d1);
    
    //构造函数将[beg，end]  区间元素拷贝给本身
    deque<int> d2(d1.begin(), d1.end());
    printDeque(d2);
    
    //构造函数将n个elem拷贝给本身
    deque<int> d3(10, 100);
    printDeque(d3);

    //拷贝构造函数
    deque<int> d4(d1);
    printDeque(d4);

}
int main(){
    test1();
    return 0;
}