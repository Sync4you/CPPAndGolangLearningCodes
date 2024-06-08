#include<iostream>
using namespace std;
class Animal{
    public:
        virtual void say(){cout << "Aniaml BARK" << endl;}
        Animal(){cout << "Animal cons" << endl;} 
        //virtual ~Animal(){cout << "Animal desctruction" << endl;}
        virtual ~Animal() = 0;//纯虚析构，类外实现，属于抽象类
};
/*
    --构造函数不能虚函数
    --静态成员函数不能是虚函数
    --内联函数不能是虚函数，编译时就展开了
*/
Animal::~Animal(){cout << "Animal chunxu des" << endl;}
class Dog:public Animal{

    public:
        virtual void say(){cout << "Dog BARK" << endl;}
        Dog(){cout << "Dog cons" << endl;}
        ~Dog(){cout << "Dog desttuction" << endl;}
};
void test(){
    Animal * an = new Dog;
    an->say();
    delete(an);
}


//抽象层，抽象类
//继承抽象类需要全部实现纯虚函数，否则也为抽象类
class Rule{
    public:
        virtual int get(int, int) = 0;
};

//实现层
class MyRule:public Rule{
    public:
        virtual  int get(int a, int b){
        return a + b ;
    }
};

//业务层
void doWork(int a, int b){
    MyRule *rule = new MyRule;
    int res = rule->get(a, b);
    cout <<res;
}
int main(void){

    test();
    //doWork(7, 4);
}