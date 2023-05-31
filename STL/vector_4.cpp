//vector赋值操作
#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int> & v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
void test1(){
    vector<int> v1;
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);

    //operator=
    vector<int> v2 = v1;
    printVector(v2);

    //assign函数
    vector<int> v3;
    //前闭后开，end指向最后一个元素的下一个位置
    v3.assign(v1.begin(), v1.end());
    printVector(v3);
    //n个elem赋值
    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);

}
int main(){

    test1();
    return 0;
}