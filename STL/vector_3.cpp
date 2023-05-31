//vector容器嵌套容器
//相当于二维数组
#include <iostream>
#include <vector>
using namespace std;


void test1(){
    vector< vector<int> > vpp;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    //向小容器插入数据
    for (int i = 0; i < 4; i++){
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }

    //向大容器插入小容器
    vpp.push_back(v1);
    vpp.push_back(v2);
    vpp.push_back(v3);
    vpp.push_back(v4);

    //通过大容器，把所有数据遍历一边
    for(vector< vector<int> >::iterator it = vpp.begin(); it != vpp.end(); it++){
        for (vector<int>::iterator itm = it->begin(); itm != it->end(); itm++){
            cout << *itm << " ";
        }
        cout << endl;
    }
}

int main(){
    test1();
    return 0;
}