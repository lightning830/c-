#include <stdio.h>
int main(void){
    void Print(int x);
    int x;
    scanf("%d",&x);
    Print(x);

    for(int i = x; i > 0;i--){
    for(int j = 0; j < 2*i-1; j++){
        printf("*");
    }
    printf("\n");
}
}

void Print(int x){
    if(x <= 0) return;
    for(int i = 0; i < 2*x-1; i++){
        printf("#");
    }
    printf("\n");
    Print(x-1);
}
