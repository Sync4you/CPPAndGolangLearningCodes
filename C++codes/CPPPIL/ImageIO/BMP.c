#include"bmp.h"
int read(int flag, FILE *fp, int start, int offset){
    if (flag == 2)
    {   
        unsigned short tmp;
        fseek(fp, start, SEEK_SET);
        fread(&tmp, 1, offset, fp);
        return (int)(tmp);
        /* code */
    }
    else if (flag == 4)
    {
        unsigned int tmp;
        fseek(fp, start, SEEK_SET);
        fread(&tmp, 1, offset, fp);
        return (int)(tmp);
        /* code */
    }
    else if(flag == 1){
        unsigned char tmp;
         fseek(fp, start, SEEK_SET);
        fread(&tmp, 1, offset, fp);
        return (int)(tmp);
    }
    else{
        return -1;
    }
    
}
int main(void){
    char *path ="D:\\download\\test.bmp";
    FILE *fp = fopen(path, "r");
    int wdt = read(2, fp, 28, 2);
    printf("%d\n", wdt);
    int isbitmap = read(2, fp, 0, 2);
    printf("%d\n", isbitmap);
    int offset = read(4, fp, 10, 4);
    printf("%d\n", offset);
    int bfSize = read(4, fp, 2, 4);
    printf("%d\n", bfSize);
    return 0;
}