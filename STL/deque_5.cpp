//deque数据存取
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
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(1);
    //opertaor[] 中括号存取
    cout << d1[0] << endl;
    d1[0] = 5;
    cout << d1.at(0) << endl;
    //at函数访问
    cout << d1.at(2) << endl;
    cout << d1.front() << endl;
    cout << d1.back() << endl;

    d1.front() = 209;
    cout << d1.front() << endl;

}

int main(){
    test1();
    return 0;
}