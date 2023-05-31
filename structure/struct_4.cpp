//关于随机数字中真随机数
#include <iostream>
#include <ctime>
using namespace std;

int main(){
    int random = rand() % 61 + 40; //这里的随机数范围是60-100； % 61 即 0-60; + 40，则范围变成40-100的范围
    //如何获取真随机数
    srand((unsigned int)time(NULL));
    int ra = rand() % 61 + 40;

    cout << random << endl;
    cout << ra << endl;

    return 0;
    
}