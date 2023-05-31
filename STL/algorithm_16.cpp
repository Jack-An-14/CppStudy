//swap算法
//互换两个容器内的元素
#include <iostream>
#include <vector>
using namespace std;
void test1(){
    vector<int> v1;
    vector<int> v2;

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);

    v2.push_back(1);
    v2.push_back(12);
    v2.push_back(3);
    v2.push_back(4);

    v1.swap(v2);
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " "  << v2[i] << endl;
    }
}
int main(){
    test1();
    return 0;
}