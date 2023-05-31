//vector预留空间
//减少vector在动态扩展
//reserve(int len) 容器预留len个元素长度，预留位置不初始化，元素不可访问。只是分配内存，并没有给数据
#include <iostream>
#include <vector>
using namespace std;
void test1(){
    vector<int> v;
    //已知数据量，可以预留空间，减少动态扩展的次数
    v.reserve(1000000);
    int num = 0;
    int* p = NULL;
    for (int i = 0; i < 1000000; i++){
        v.push_back(i);

        if(p != &v[0]){
            p = &v[0];
            //动态扩展的次数
            num++;
        }
    }

    cout << num << endl;
}

int main(){
    test1();
    return 0;
}