//vector插入和删除
#include <iostream>
#include <vector>
using namespace std;
/*
push_back(elem)尾插，在vector尾部插入elem
pop_back() 删除最后一个元素
insert(const iterator pos, ele)  迭代器指向位置插入elem
insert(const iterator pos, int count, ele) 迭代器指向位置插入count个elem元素
erase(const iterator pos)  删除指向位置的元素
erase(const iterator brgin, const iterator end) 删除begin到end位置的元素
clear() 删除容器中所有元素
*/

void printVector(vector<int> & v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test1(){
    vector<int> v1;
    //尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1);

    //尾删
    v1.pop_back();
    v1.pop_back();
    printVector(v1);

    //插入
    //第一个参数是位置的迭代器，第二个参数是数据
    v1.insert(v1.begin(), 100);
    printVector(v1);
    
    v1.insert(v1.begin(), 10, 100);
    printVector(v1);

    v1.insert(v1.begin(), 10000);
    printVector(v1);
    //删除参数为位置迭代器
    v1.erase(v1.begin());
    printVector(v1);

    //区间删除，两个参数都是位置迭代器
    // v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector(v1);

    

}

int main(){

    test1();
    return 0;
}