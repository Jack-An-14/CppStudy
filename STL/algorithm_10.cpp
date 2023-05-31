//random_shuffle
//洗牌，指定范围内的元素随机调整次序
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
void myprint(int val){
    cout << val << " ";
}
void test1(){
    srand((unsigned int)time(NULL));
    vector<int> v;
    for (int i = 0; i < 10; i++){
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), myprint);
    cout << endl;
    //洗牌算法 每一次打乱的结果,可以设置时间种子。得到真随机数
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myprint);
    cout << endl;
}
int main(){
   
    test1();
    return 0;
}