#include<iostream>
#include<stdexcept>
using namespace std;

class Maker{
    public:
        int a;
        Maker(){cout << "maker cons" << endl;}
        ~Maker(){cout <<" maker dest" << endl;}
        Maker(const Maker &m){
            this->a = m.a;
            cout << "maker copy cons" << endl;
        }
};
void func1(){
    Maker m;
    throw m;//拷贝构造
}
void func2(){
    throw Maker();
}
void func3(){
    throw new Maker();
}
void test01(){
    try
    {
        func1();
    }
    catch(Maker m1) //拷贝构造
    //加引用&,就不是构造
    {
        cerr << "Maker tyep error" << endl;
    }
    
}
void test02(){
    try{
        func2();
    }
    catch(Maker &m){
        cerr << "Maker tyep error" << endl;
    }
}
void test03(){
    try{
        func3();
    }
    catch(Maker *m){
        cerr << "Maker tyep error" << endl;
        delete m;
    }
}

class Person{
    public:
        int age;
        Person(int a){
            if( a <= 0) 
                throw out_of_range("invalid age!");
            else
                this->age = a;
        }

};
void test04(){
    try{
        Person p(-8);
    }
    catch(out_of_range & excp){
        cerr << excp.what() << endl;
    }
    

}
int main(){
    //test01();
    //test02();
    //test03();
    test04();
}