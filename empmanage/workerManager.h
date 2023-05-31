#pragma once    //防止头文件重复包含
#include <iostream> //包含输入输出流头文件

using namespace std;

class WorkerManager{
    public:
        WorkerManager();

        ~WorkerManager();

        void Show_Menu();

        void ExitSystem();
};