//一元谓词
#include <iostream>
#include <vector>
using namespace std;

//仿函数，返回值是bool数据类型
class Greaterfive{
    public:
        //返回值为bool，参数列表中只有一个参数。 称为一元谓词。
        bool operator()(int val){
            return val > 5;
        }
};

void test1(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    //查找容器中，有没有大于5的数字
    //Greaterfive()匿名函数对象
    //find_if()参数为两迭代器和一个自定义的仿函数
    vector<int>::iterator it = find_if(v.begin(), v.end(),Greaterfive());
    if(it == v.end()){
        cout << "未找到" << endl;
    }
    else{
        cout << "找到了" << *it << endl;
    }
}


int main(){
    test1();
    return 0;
}