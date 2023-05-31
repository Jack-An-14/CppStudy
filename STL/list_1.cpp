//list构造
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
    //默认构造
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printlist(l1);

    //区间方式构造
    list<int> l2 (l1.begin(), l1.end());
    printlist(l2);

    //拷贝构造
    list<int> l3(l1);
    printlist(l3);

    //n个elem,一个参数为个数，第二个参数为elem
    list<int> l4(10, 100);
    printlist(l4);
}
int main(){
    test1();
    return 0;
}