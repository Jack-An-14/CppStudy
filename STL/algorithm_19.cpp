//set算法
//交、并、差
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void test1(){
    vector<int> v1;
    vector<int> v2;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

    v2.push_back(20);
    v2.push_back(40);
    v2.push_back(50);

    vector<int> target;
    //提前开辟空间。交集最特殊的情况就是大容器包含小容器
    // target.resize(min(v1.size(), v2.size()));
    //并集特殊情况，size相加
    // target.resize(v1.size()+v2.size());
    //差集最特殊情况 max(size)
    // target.resize(max(v1.size(), v2.size()));
    target.resize(10);
    vector<int>::iterator itend ;
    itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    itend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    for (vector<int>::iterator it = target.begin(); it != itend; it++){
        cout << *it << " ";
    }
    cout << endl;
    cout << *itend << endl;
}
int main(){
    test1();
    return 0;
}