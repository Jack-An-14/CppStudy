//常用排序算法
//sort算法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool Comp(int v1, int v2){
    return v1 > v2;
}

void myprint(int val){
    cout << val << " ";
}
void test1(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(4);

    sort(v.begin(),v.end(), Comp);
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myprint);
    cout << endl;

}
int main(){
    test1();
    return 0;
}