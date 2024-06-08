#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mem_p1(char* p){
    p = malloc(512);
    *p = 'P';
    return ;
}


void mem_p2(char **k){
    *k = malloc(1024);
    return ;
}

int main(void)
{
    char * p = NULL;
    //mem_p1(p);
    mem_p2(&p);
    strcpy(p, "jijdwa");
    printf("p==%s", p);
    return 0;
}
