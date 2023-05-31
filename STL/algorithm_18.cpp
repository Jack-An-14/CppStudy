#include <iostream>
#include <vector>
using namespace std;

//常用算数生成算法fill
void test1(){
    vector<int> v;
    v.resize(10);
    fill(v.begin(), v.end(), 100);
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << endl;
    }
}

int main(){
    test1();
    return 0;
}
