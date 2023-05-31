//deque大小操作
#include <iostream>
#include <deque>
using namespace std;
//和vector类似，没有容量限制
//deque没有容量概念
void printDeque(const deque<int> & d){
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

void test1(){
    deque<int> d1;
    for (int i = 0; i < 10; i++){
        d1.push_back(i);
    }
    printDeque(d1);

    if(d1.empty()){
        cout << "空" << endl;
    }
    else {
        cout << "不为空" << endl;
        cout << d1.size() << endl;
    }

    d1.resize(15);
    printDeque(d1);

    d1.resize(20,7);
    printDeque(d1);
}
int main(){
    test1();
    return 0;
}