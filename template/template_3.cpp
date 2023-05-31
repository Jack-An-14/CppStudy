//函数模版实例
#include <iostream>
using namespace std;
template <typename T>
void mySort(T arr[], int length){
    for (int i = 0; i < length; i++){
        int max = i;//认定最大值下标
        for (int j = i+1; j < length; j++){
            if(arr[max] < arr[j]){
                max = j;
            }
        }
        if(max != i){
            T temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;    
        }
        
    }
}
void test(){
    char str[] = "badcfe";
    mySort(str, sizeof(str)/sizeof(char));

    cout << str << endl;
}
int main(){
    test();
    return 0;
}