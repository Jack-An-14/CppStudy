#include <iostream>
#include "workerManager.cpp"
#include "worker.h"
#include "employee.cpp"
using namespace std; 

void test(){
    Worker * worker = NULL;
    worker = new Employee(1, "张三", 1);
    worker->showInfo();
    delete worker;

}
int main(){

    //实例化管理者对象
    WorkerManager wm;
    int choice = 0;
    test();
    while(true){
        wm.Show_Menu();
        cout << "请输入您的选择" << endl;
        cin >> choice;

        switch(choice){
            case 0:
                wm.ExitSystem();
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            default:
                system("cls");
                break;
        }
    }
    
    system("pause");
}