#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
void test1()
{
    int a = 14;
    int &ref = a;
    int b = 5;
    int &ref2 = b;
    // ref = NULL;
    ref = ref2;//a = b = 5了
    //引用确定了方向不可变
    //ref = b本质上给ref指向的地址内存赋b的值
    //引用声明了就必须需要初始化
    cout << &a << " " << &ref << endl;
    cout << a << " " << ref << endl;
    cout << &b << " "<< &ref2 << endl;
    cout << b << " " << ref2 << endl;
}

int ret()
{
    int n = 2;
    n++;
    return n;
}
void test1(char* &p){
    //指针的引用
    char * q;
    q = (char*)malloc(64);
    memset(q, 0, 64);
    strcpy(q, "Zaly");
    p = q;
}
void test2(){
    char *mp = NULL;
    test1(mp);
    cout <<
    mp <<endl;
}
void test3(int &a, int &b){
    a = 4;
    b = -7;
}
int& func(){
    int a = 9;//错误，局部变量引用禁止返回
    
    int &p = a;
    return p;
    //引用作为返回值
}
void test4(){
    int &q = func();
    cout << q << endl;
}
int& func2(){
    static int a =9;
    return a;
}
int main()
{
    /* int a = ret();
    cout << "daw" << endl;
    cout << a; */
    /* int a1 = 70, a2 = -89;
    test3(a1, a2);
    cout<< a1<< " "<< a2 << endl; */
    //test1();
    //test2();
    //test4();
    func2() = 8;
    cout<<func2()<<endl;    
}