//transform算法
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class transf{
    public:
        int operator()(int val){
            return val;
        }
};

void print1(int val){
    cout << val << " ";
}
void test1(){
    vector<int> v;
    for(int i = 0; i < 10; i++){
        v.push_back(i);
    }

    vector<int> target;
    target.resize(v.size());
    transform(v.begin(), v.end(), target.begin(), transf());

    for_each(target.begin(), target.end(), print1);
    cout << endl;
}

int main(){
    test1();
    return 0;
}