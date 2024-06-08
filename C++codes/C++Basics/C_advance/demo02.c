#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void test1(){
    char *p =NULL;
    strcpy(p, "jida");
    //char *q =0x1122;
   // strcpy(q, "oiia");
    printf("%d ", *p);

}
void test2(){
    char str1[] = "jidada";
    char *str2 = "olladw";
    char s[] = "kidwad";
    char * str3 = s;
    str1[0] = 'Q';
    str2[0] = 'Q';
    str3[0] = 'Q';
    printf("%s\n%s\n%s\n", str1, str2, str3);
}
int main(){
    //test1();
    test2();
}