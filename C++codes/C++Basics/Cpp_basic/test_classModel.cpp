#include<iostream>
using namespace std;
class NullClass{};
class Maker{
    public:
        float f;
        mutable int g;
        Maker(){}
        void fun1(){}
        void fun2(){cout << "ss" << endl;}
        void modifyNum() const{ 
            //f = 0.214f;
            //常函数
            //无法修改普通变量
            //mutable 可以修改
            //this->f = 0.15f;
            //
            //g = 14;
            this->g = 1;
            cout << "g==" << g << endl;
        }
    private:
        /* int a;
        bool b;
        char c;
        char d; */
        //bool e;
        /* long ll; */
};
int main(void){
    //cout << sizeof(NullClass);//空类大小为1， 编译器好区分内存中的对象
    //成员函数不计大小
    //静态成员变量不计入大小
    cout << sizeof(Maker);// 最低4字节，且是4的倍数
    Maker m;
    m.modifyNum();
    //const Maker mm; //常对象
    Maker const mm;
    mm.modifyNum(); //长对象和普通对象都可以调用常函数
    //mm.fun2(); //无法调用普通函数
   // mm.f = 55; //无法修改普通变量
    mm.g = 77; //可以修改mutable 变量
}