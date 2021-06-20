#include<stdio.h>
int main(){
    int H,A,count;
    scanf("%d",&H);
    scanf("%d",&A);

    int i;
    for(i = 1;;i++){
        H -= A;
        if(H <= 0){
            break;
        }
    }
    printf("%d", i);
}