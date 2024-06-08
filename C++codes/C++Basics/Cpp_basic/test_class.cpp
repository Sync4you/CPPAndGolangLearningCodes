#include<iostream>
#include<string.h>
using namespace std;
class CAR{};
class BIKE{};
class MAKER{
    public:
        static int b;
        const static char c = 'U';//const 静态最好类内初始化
        MAKER(){ cout << "无参数构造" << endl;}
        explicit MAKER(int a){this->a = a;cout << "带参数构造" << endl;}
        ~MAKER(){ cout<< "析构函数" << endl; }
        MAKER(const MAKER& m){
            cout << "拷贝构造" << endl;
            a = m.a;
        }
        static void setStatic(int bb){
           // b = bb;
            //a = bb; error,non-static variable
            MAKER::b = bb;//两种都可以修改
        }
        static void showNum(){ cout << b << endl;}
        //如果用户提供类的无参构造或者有参构造函数，编译器不提供默认的构造函数
        //如果用户提供类的拷贝构造函数，编译器不提供默认的构造和拷贝构造函数
        void printMAKER(){  cout << a << endl;}

    private:
        int a;
        CAR car;
        BIKE bike;
        /*
        成员对象先构造，析构反之。构造顺序和定义一样。保证成员对象构造，析构函数能调用。
        */
};
int MAKER::b = 10;//静态成员变量类外初始化
MAKER func_LocalClass(){
    MAKER m;
    cout << "局部对象address：" << &m << endl;
    return m;
}
void test1(){
    MAKER mm = func_LocalClass();
    cout << "mm对象地址" << &mm << endl;
}
class Person {
private:
    char* name;
 
public:
    // 构造函数
    Person(const char* n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
 
    // 拷贝构造函数
    Person(const Person& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
 
    // 析构函数
    ~Person() {
        delete[] name;
    }
 
    // 获取姓名
    const char* getName() const {
        return name;
    }
    void setName(char* n){
        strcpy(name, n);
    }
};
int main(){
    /* MAKER* m = new MAKER();
    m->printMAKER();  */
   /*  MAKER m1(2);
    m1.printMAKER();
    MAKER m2(m1);
    m2.printMAKER(); */

  /*  MAKER();
   MAKER(14); *///匿名对象,生命期为当前行

   // test1();

   //MAKER m = 14;//发生隐式转换
   // MAKER m = 14.2;//同上
   // m = 'o'; //'O' 转换成ASCII码， 111
   // m.printMAKER();

   /*  Person p1("Mark");
    Person p2(p1); //浅拷贝
    char ps[] = "SHABI";
    p2.setName(ps);
    cout << p1.getName() << endl;
    cout << p2.getName() << endl; */

    MAKER::showNum();
    MAKER::setStatic(7);
    MAKER::showNum();
    return 0;

}