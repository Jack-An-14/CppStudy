//vector容量和大小
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

    if(v1.empty()){
        cout << "为空" << endl;
    }
    else {
        cout << "不为空" << endl;
        //vector的容量 >= vector的大小
        cout << v1.capacity() << endl;
        cout << v1.size() << endl;
    }

    //重新指定大小
    v1.resize(20, 0);//重新指定的大小比原先大，默认用0填充剩余位置
    printVector(v1);

    v1.resize(4);//重新指定的大小比原先小，剩余的位置会被删除释放
    printVector(v1);
}
int main(){
    test1();
    return 0;
}