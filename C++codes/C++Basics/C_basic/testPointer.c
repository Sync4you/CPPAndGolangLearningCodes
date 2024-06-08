#include<stdio.h>
#include<stdlib.h>


void testPointerAddr(){
    char a = 'A', b = 'B';
    char *pointer_a = &a;
    pointer_a = &b;

    char ** p_pointer_a = &pointer_a;
    printf("%c\n", *pointer_a);
    printf("%p\n", pointer_a);
    printf("%p\n", &b);
    printf("%p\n", *p_pointer_a);

}

void testPointerSize(){
    int * p1;
    char *p2;
    short *p3;
    long *p4;
    int ** p5;
    printf("%d\n", sizeof(p1));
    printf("%d\n", sizeof(p2));
    printf("%d\n", sizeof(p3));
    printf("%d\n", sizeof(p4));
    printf("%d\n", sizeof(p5));

}

void testPointerWidth(){
    int num = 0x01025312;
    int * p1 = &num; //4B
    short *p2 = (short *)&num;//2B
    char * p3 = (char *)&num;//1B
    printf("%x\n", *p1);
    printf("%x\n", *p2);
    printf("%x\n", *p3);
   
}

void testPointerStride(){
    int num = 0x01071772;
    int * p1 = &num; 
    short *p2 = (short *)&num;
    char * p3 = (char *)&num;
    printf("%p\n", p1);
    printf("%p\n", p2);
    printf("%p\n", p3);
    printf("%p\n", p1 + 1);
    printf("%p\n", p2 + 1);
    printf("%p\n", p3 + 1);

}

void testPointerVoider(){
    int a = 10;
    short b = 5;
    void * p = (void *) &a;
    void * q = (void *) &b;
    printf("%d\n", *(int *)p);


}

testPointerConst(){
    int c = 4;
    int a = 2;
    int *const p = &a;//指针常量
    const int * q = &a;//常量指针
    //p = &c; err: ， 指向地址不能改
   
    //*q = 4; err: ， 不能改const 指针的指向的内容
    printf("%d\n", *p);
    printf("%d\n", *q);

}

int main(){

    int year=0, mon=0, day =0;
    char buf[512] = "2012:14:11";
    sscanf(buf, "%d:%d:%d", &year, &mon, &day);
    printf("%d,%d, %d", year, mon, day);
    //testPointerConst();
    //testPointerVoider();
    //testPointerStride();
    //testPointerWidth();
    //testPointerSize();
    //testPointerAddr();
}