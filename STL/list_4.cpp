//list容器插入和删除
#include <iostream>
#include <list>
using namespace std;

void printlist(const list<int> & l){
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test1(){
    list<int> l1;
    //尾插push_back
    l1.push_back(10);
    l1.push_back(20);
    printlist(l1);

    //尾删pop_back
    l1.pop_back();
    printlist(l1);

    //头插push_front
    l1.push_front(30);
    l1.push_front(110);
    printlist(l1);

    //头删pop_front
    l1.pop_front();
    printlist(l1);

    list<int>::iterator it = l1.begin();
    //迭代器向后偏移2个位置
    it++;
    it++;
    //insert函数
    //指定位置插入
    l1.insert(it, 900); //这个insert重载会返回插入数据的位置迭代器
    printlist(l1);
    
    //指定位置连续插入n个elem
    l1.insert(it, 9, 10);
    printlist(l1);
    //在指定位置，插入区间的元素
    // l1.insert(it, l1.begin(), l1.end());
    // printlist(l1);
    //删除区间元素
    // l1.erase(l1.begin(), l1.end());
    // printlist(l1);
    //删除容器中所哟elem值
    l1.remove(10);
    printlist(l1);

}
int main(){
    test1();
    return 0;
}