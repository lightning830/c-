#include <stdio.h>
#include<stdlib.h>
int main(void){
    int n,i,j;
    printf("enter number");
    scanf ("%d",&n);

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            printf("%d", j%10);
        }
        system("cls");
        printf("\n");
    }


}

