#include<stdio.h>
#include<string.h>

int main(void) {
    int a[3] = {1,2,3};
    int *p = a;
    int *q = p;
    p++;
    printf("%d\n", *q);
    //1: その時のpが指すアドレスをコピーするから変化しない
    printf("%d\n", *p);
    //2


    int a[3] = {1,2,3};
    int *p = a;
    int **q = &p;
    p++;
    printf("%d\n", **q);
    //2: p自体のアドレスをコピーするから変化する
    printf("%d\n", *p);
    //2
} 
