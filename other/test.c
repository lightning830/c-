#include<stdio.h>
#include<string.h>

struct kid
{
    /* data */
    char name[50];
    struct kid *next;
};

void printNode(struct kid *pkid){
    struct kid *p = pkid;
    while (p != NULL)
    {
        /* code */
        printf("%s\n", pkid->name);
        pkid = pkid -> next;
    }
    
}

int main(){
    struct kid mun, kou, tom;
    strcpy(mun.name, "munehiro");
    mun.next = NULL;
    strcpy(kou.name, "kouichi");
    kou.next = &mun;
    strcpy(tom.name, "tomofumi");
    tom.next = &kou;


    printNode(&tom);
}