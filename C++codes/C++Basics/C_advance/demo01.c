#include<stdio.h>
#include<stdlib.h>

const int a = 10;
void testConst1(){
    //a = 50; 直接修改失败，储存在常量区

/*
    int *p =&a;
    *p = 5;
    printf("%d", *p);  //间接修改失败
*/

}

void testConst2(){
    const int b = 2;
    //b = 5; failed
   const  int *p = &b;//伪常量
    //*p = 3;
    //int arr[b] ;
    printf("%d", *p);
}
int main(){
    testConst2();
    //testConst1();
}