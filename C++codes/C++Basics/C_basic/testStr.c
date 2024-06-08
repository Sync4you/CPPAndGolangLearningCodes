#include<stdlib.h>
#include<stdio.h>
void testGets(){

    char num[128]="";
    gets(num);
    printf("%s", num);

}

void testFgets(){
    char buf[1024] = "";
    fgets(buf, sizeof(buf), stdin);
    printf("%s", buf);
}
void testTo(){
    int num = atoi("48da");
    float fl = atof("3.145488p");
    printf("%d", num);
    printf("%f", fl);

}
int main()
{
    testTo();
    //testGets();
    //testGets();
    return 0;

}
