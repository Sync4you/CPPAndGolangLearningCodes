#include<stdio.h>
#include<stdlib.h>

int add(int a, int b){ return a +b;}
int sub(int a, int b){return a -b;}
int main(void)
{
    int (*p)(int, int) = sub;
    printf("%d\n", p(4, 1));
    p = add;
    printf("%d\n", p(4, 1));

    return 0;
}
