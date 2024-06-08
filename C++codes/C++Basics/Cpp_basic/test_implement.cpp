#include<iostream>
#include<string>
using namespace std;
class Father{
    private:
        char sexNum;
    public:
        int age;
        static int a;
        Father(int age, char sN){this->age = age;this->sexNum = sN;}
        void show(){cout << "Father:" << this->age << " " << this->sexNum  << endl;}
};
class Son:public Father{
    private:
        char sexNum;
    public:
        int age;
        static int a;//静态成员会被继承，同样也会被隐藏
        Son(int sAge, char sSN, int fAge, char fSN):Father(fAge, fSN){
            this->age = sAge;
            this->sexNum = sSN;
        }
        void show(){cout << "Son" << this->age << " " << this->sexNum << endl;}
};
int Father::a = 1;
int Son::a = 7;
/*
    --构造函数和析构函数不能被继承
    --继承父类的静态成员变量属于父类的
    --改变继承的静态成员函数某个特征（参数个数，返回值，..）会隐藏基类的
    --静态函数不能为虚函数 

*/
class Animal{
    public:
        string name = "Animal";
        int a = 10;
        Animal(){}
        void say(){cout << this->name << endl;}
        virtual void bark(){cout << "BARK!" << endl;}
};
class Sheep: virtual public Animal{};
class Camel: virtual public Animal{};
class SheepCamel:public Sheep, Camel{};
//菱形继承需要virtual关键字，防止二义性
/*
    -- 静态联编 早绑定，编译阶段确定
    -- 动态联编 晚绑定， 运行阶段确定
    虚函数，说明晚绑定
    好处：不修改项目前面代码，进行功能的扩充
*/
int main(void){
   /*  Father f(15, 'B');
    f.show();
    Son s(7, 'A', 25, 'D');
    s.show();
    cout << s.a; */
   /*  SheepCamel sc;
    //cout << sc.name;//二义性
    cout << sc.name ;//虚继承 */
    return 0;
}