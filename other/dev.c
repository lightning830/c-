#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(void) {

 char a[100];
 char b[100] = { 0 };
 char c[100] = { 0 };
 

 void eng(char x[],char y[]);
 void num(char x[], char y[]);
 void Sort(char x[]);
 void Swap(char** x, char** y);

 printf("���́F\n");
 gets (a);
    //printf("%s", a);

 eng(a, b);
 num(a, c);
 

 printf("\n�o�́F\n");
 printf("�p���F%s\n", b);
 printf("�����F%s\n", c);

 //���ёւ�
 
 //printf("ok1");
 printf("�p��(����)�F");
 Sort(b);
 printf("�p��(����)�F");
 Sort(c);

 return 0;
}

void eng(char x[],char y[]) {
 int i;
 int j = 0;
 int k;
 k = strlen(x);
 for (i = 0; i < k; i++) {
  if ((x[i] >= 'a' && x[i] <= 'z') || (x[i] >= 'A' && x[i] <= 'Z')) {
   y[j] = x[i];
   j++;
  }
 }
}

void num(char x[], char y[]) {
 int i;
 int j = 0;
 int k;
 k = strlen(x);
 for (i = 0; i < k; i++) {
  if (x[i] >= '0' && x[i] <= '9') {
   y[j] = x[i];
   j++;
  }
 }
}

void Swap(char** x, char** y) {

 char *c;
  c = *x;
 *x = *y;
 *y = c;
} 

void Sort(char* x) {

    char *t[100];
    for(int i = 0; i < 100; i++){
        t[i] = &x[i];
    }
    while(1){
        int flag = 1;
        for(int i = 0; i < (100)-1; i++){
            if(strcmp(t[i], t[i+1]) > 0 && *t[i+1] != '\0'){
                flag = 0;
                Swap(&t[i], &t[i+1]);
            }
        }
        if(flag) break;
    }
    for(int i = 0; i < 100; i++){
        printf("%c",*t[i]);
    }
    printf("\n");

}


