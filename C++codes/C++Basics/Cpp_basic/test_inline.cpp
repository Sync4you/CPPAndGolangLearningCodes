#include<iostream>
using namespace std;
#define ADD(x, y) x + y
inline int add(int x, int y){return x + y;}
void test1(){
    cout << ADD(10, 12) * 4 << endl;//58宏函数结果错误，缺点是式子展开，按算数优先级
    cout << add(10, 12) * 4 << endl;//88 内联函数结果正确
}
//不成为inline函数的情况
/* --1 存在过多的条件判断语句
   --2 函数体过大
   --3 函数取地址操作
   --4 存在任何形式的循环语句
   inline 弱关键字，看编译器决定，类的成员函数都是inline函数
*/
/*  
1. 内联函数在执行时调用-编译，而宏定义不可以-预处理阶段；
2. 编译器会对内联函数的参数类型做安全检验或自动类型转换，而宏定义不会；
3. 内联函数可以访问类的成员变量，而宏定义不能。
*/
int main(){
    test1();
    return 0;
}