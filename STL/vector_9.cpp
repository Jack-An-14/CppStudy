//vector互换容器，实现两个容器内的元素进行互换
//swap函数
#include <vector>
#include <iostream>
using namespace std;
void printVector(vector<int> & v){
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}
//1、基本使用
void test1(){
    vector<int> v1;
    for (int i = 0; i < 10; i++){
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    for (int i = 10; i > 0; i--){
        v2.push_back(i);
    }
    printVector(v2);

    v1.swap(v2);
    //v1和v2互换容器内的元素
    printVector(v1);
    printVector(v2);
    
}
//2、实际用途
//使用swap收缩内存空间
void test2(){
    vector<int> v;
    for (int i = 0; i < 10000000; i++){
        v.push_back(i);
    }
    cout << v.capacity() << endl;
    cout << v.size() << endl;
    //重新指定大小，容量不会发生变化，大小会改变
    v.resize(3);
    cout << v.capacity() << endl;
    cout << v.size() << endl;

    vector<int>(v).swap(v);
    //这里容器交互。首先vector<int>(v)会创建一个匿名对象，调用拷贝构造函数，拷贝v的size。然后调用swap函数，容器交换，容量缩小。编译器识别到匿名对象后，多余的内存空间会被回收。
    cout << v.capacity() << endl;
    cout << v.size() << endl;

}
int main(){
    // test1();
    test2();
    return 0;
}