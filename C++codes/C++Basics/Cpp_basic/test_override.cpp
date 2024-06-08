#include<iostream>
using namespace std;
/*
    重载的条件————
    同一个作用域
    参数个数不同
    参数类型不同
    参数顺序不同
    返回值类型相同
*/
int get(int, int);
int get(int);
int get(int a, int b){return a + b;}
int get(int a){return a;}

int main(){

    cout << get(14, 6) << " " << get(-1 * 7) <<endl;
    return 0;
}