//list赋值和交换
#include <iostream>
#include <list>
using namespace std;
void printlist(const list<int> & l){
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

//赋值
void test1(){
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    printlist(l1);

    list<int> l2 = l1;
    printlist(l2);

    list<int> l3;
    l3.assign(l1.begin(), l1.end());
    printlist(l3);
    //n个elem
    list<int> l4;
    l4.assign(10, 100);
    printlist(l4);

}

//交换
void test2(){
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    list<int> l4;
    l4.assign(10, 100);
    printlist(l1);
    printlist(l4);

    //交换后
    l1.swap(l4);
    printlist(l1);
    printlist(l4);
}
int main(){
    // test1();
    test2();
    return 0;
}