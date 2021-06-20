#include<stdio.h>
int main(){
    int a1, a2, a3;
    scanf("%d %d %d", &a1, &a2, &a3);
    
    if((a1+a2+a3) >= 22) printf("bust");
    else printf("win");
    return 0;
}