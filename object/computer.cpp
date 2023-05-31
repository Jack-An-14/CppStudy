//多态案例三-电脑组装
#include <iostream>
using namespace std;
class CPU{
    public:
        virtual void calculate() = 0;
        virtual ~CPU(){
            cout << "CPU析构函数执行" << endl;
        }
};

class VideoCard{
    public:
        virtual void display() = 0;

        virtual ~VideoCard(){
            cout << "VideoCard析构函数执行" << endl;
        }
};

class Memory{
    public:
        virtual void storage() = 0;

        virtual ~Memory(){
            cout << "Memory析构函数执行" << endl;
        }
};

class IntelCPU : public CPU{
    public:
        void calculate(){
            cout << "Intel的CPU开始计算" << endl;
        }
        ~IntelCPU(){
            cout << "IntelCPU析构函数执行" << endl;
        }
};

class IntelVideoCard : public VideoCard{
    public:
        void display() {
            cout << "Intel的显卡开始工作" << endl;
        }
        ~IntelVideoCard(){
            cout << "IntelVideoCard析构函数执行" << endl;
        }
};

class IntelMemory : public Memory{
    public:
        void storage() {
            cout << "Intel的内存开始工作" << endl;
        }
        ~IntelMemory(){
            cout << "IntelMemory析构函数执行" << endl;
        }
};

class NividaCPU : public CPU{
    public:
        void calculate(){
            cout << "Nivida的CPU开始计算" << endl;
        }

        ~NividaCPU(){
            cout << "NividaCPU析构函数执行" << endl;
        }

};

class NividaVideoCard : public VideoCard{
    public:
        void display() {
            cout << "Nivida的显卡开始工作" << endl;
        }

        ~NividaVideoCard(){
            cout << "NividaVideoCard析构函数执行" << endl;
        }

};

class NividaMemory : public Memory{
    public:
        void storage() {
            cout << "Nivida的内存开始工作" << endl;
        }

        ~NividaMemory(){
            cout << "NividaMemory析构函数执行" << endl;
        }
};

class Computer{
    private:
        CPU * cpu;
        VideoCard * videocard;
        Memory * memory;

    public:
        Computer(CPU * cpu, VideoCard * videocard, Memory * memory){
            this->cpu = cpu;
            this->videocard = videocard;
            this->memory = memory;
        }
        void work(){
            cpu->calculate();
            videocard->display();
            memory->storage();
        }

        ~Computer(){
            if(this->cpu != NULL){
                delete this->cpu;
                this->cpu = NULL;
            }

            if(this->videocard != NULL){
                delete this->videocard;
                this->videocard = NULL;
            }

            if(this->memory != NULL){
                delete this->memory;
                this->memory = NULL;
            }
            cout << "Computer析构函数开始执行" << endl;
        }
};

void test(){
    CPU * c = new NividaCPU;
    VideoCard * v = new IntelVideoCard;
    Memory * m = new NividaMemory;

    Computer * computer = new Computer(c, v, m);
    computer->work();
    delete computer;

    computer = new Computer(new IntelCPU, new IntelVideoCard, new NividaMemory);
    computer->work();
    delete computer;
}




int main(){
    test();
    return 0;
}