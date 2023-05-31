//指针和函数
#include <iostream>

using namespace std;

void bubbleSort(int* p, int length){
    for (int i = 0; i < length-1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if(p[j] > p[j+1]){
                int temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }   
}
int main() {
    int arr[] = {19, 5, 6, 7};
    bubbleSort(arr, 4);
    for (int i = 0; i < 4; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}

