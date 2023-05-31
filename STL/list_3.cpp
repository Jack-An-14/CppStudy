//list大小操作
#include <iostream>
#include <list>
using namespace std;

void test1(){
    list<int> l1;
    cout << l1.size() << endl;

    l1.push_back(10);
    l1.push_back(10);
    l1.push_back(10);
    l1.push_back(10);

    if(l1.empty()){
        cout << "空" << endl;
    }
    else {
        cout << "不为空" << endl;
        l1.resize(10, 9);
    }

    for(list<int>::iterator it = l1.begin(); it != l1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
int main(){
    test1();
    return 0;
}