#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Beverage{
    char* name;
    int price;
    int count;
    struct Beverage* next;
};

struct Money{
    int type;
    int count;
    struct Money* next;
};

const int money_type[] = {10, 50, 100, 500, 1000, 5000};
const int password = 999;//パスワード
struct Beverage* beverage = NULL;
int beverage_len = 0;//商品の個数
struct Money* money = NULL;

void setting(){//初期設定、お金の線形リスト作成
    int size = sizeof(money_type)/sizeof(*money_type);
    for(int i = 0; i < size; i++){
        struct Money* p = (struct Money*)malloc(sizeof(struct Money));
        p->type = money_type[i];
        p->count = 0;
        p->next = money;
        money = p;
    }
}

void add_money(int type, int num){//リストにお金を追加する
    struct Money* p = money;
    while(p != NULL){
        if(p->type == type){
            p->count += num;
            // printf("successed in adding %d of %d yen! \n", num, type);
            return;
        }
        p = p->next;
    }
    return;
}

void sub_money(int type, int num){//リストのお金を減らす
    struct Money* p = money;
    while(p != NULL){
        if(p->type == type){
            p->count -= num;
            if(p->count < 0) p->count = 0;
            // printf("successed in taking %d of %d yen! \n", num, type);
        }
        p = p->next;
    }
}

void print_money(){//お金の現在の状況
    struct Money* p = money;
    printf("---MONEY INVENTRY---\n");
    while(p != NULL){
        printf("count:%d -> %d\n", p->type, p->count);
        p = p->next;
    }
    printf("--------------------\n");
}

void add_beverage(char* name, int price, int count){//商品をリストに追加
    struct Beverage* p = beverage;
    //線形リストがない場合
    if(p == NULL){
        p = (struct Beverage*)malloc(sizeof(struct Beverage));
        p->next = NULL;
        p->name = name; p->price = price; p->count = count;
        beverage = p;
        beverage_len++;
        return;
    }
    //ある場合
    while(p != NULL){
        if(!(strcmp(p->name, name))){
            p->count += count;
            return;
        }
        p = p->next;
    }
    //あるが、その商品が入ってない場合
    struct Beverage* tmp = beverage;
    tmp = (struct Beverage*)malloc(sizeof(struct Beverage));
    tmp->name = name; tmp->price = price; tmp->count = count;
    tmp->next = beverage;
    beverage = tmp;
    beverage_len++;
    return;
}

void sub_beverage(char* name, int count){//商品をリストから減らす
    struct Beverage* p = beverage;
    //線形リストがない場合
    if(p == NULL){
        printf("no beverage\n");
        return;
    }
    //ある場合
    while(p != NULL){
        if(!(strcmp(p->name, name))){
            p->count -= count;
            if(p->count < 0) p->count = 0;//残り個数は負にならない
            return;
        }
        p = p->next;
    }
    //あるが、その商品が入ってない場合
    printf("no that beverage\n");
    return;
}

void print_beverage(){//商品の在庫の現在の状況
    struct Beverage* p = beverage;
    printf("---BEVERAGE INVENTRY---\n");
    while(p != NULL){
        printf("name:%s price:%d count:%d\n", p->name, p->price, p->count);
        p = p->next;
    }
    printf("-----------------------\n");
}

void print_menu(){//メニューを表示
    int i = 1;
    struct Beverage* p = beverage;
    printf("-----------MENU-----------\n");
    while(p != NULL){
        if(p->count == 0) printf("%d %s %dyen (SOLD OUT)\n", i, p->name, p->price);
        else printf("%d %s %dyen\n", i, p->name, p->price);
        i++;
        p = p->next;
    }
    printf("--------------------------\n");
}

void admin(){//管理者モード関数
    printf("***Administrator Mode***\n");
    while (1){
        printf("1: beverage management, 2: exit\n");//いろんな機能をつけていこう、続きを書く
        int x; scanf("%d", &x);
        if(x == 1){
            printf("1: add, 2: substract 3: exit\n");
            int y; scanf("%d", &y);
            if(y == 1){
                printf("~~~~~add~~~~~\n");//商品を追加する、続きをかく
            }else if(y == 2){
                printf("~~~~~substract~~~~~\n");//商品を削除する、続きを書く
            }else if(y == 3) break;
        }else if(x == 2) break;
    }
    
}

int main(){
    setting();
    add_money(1000, 5);//お金リストに1000円を5つ追加
    add_money(100, 10);
    add_money(100, 1);
    add_money(50, 3);
    print_money();
    sub_money(1000, 2);//1000円を2つ減らす
    sub_money(50, 10);
    print_money();

    add_beverage("apple", 100, 5);//appleを100円で5つリストに追加
    add_beverage("banana", 50, 10);
    add_beverage("apple", 100, 1);
    print_beverage();
    sub_beverage("apple", 3);//appleを3つ削除
    sub_beverage("apple", 1);
    sub_beverage("banana", 20);
    print_beverage();
    // print_menu();
    int x;
    while(1){
        print_menu();//メニュー表示
        printf("WELCOME! select beverage. if you don't need, type '-1'\n");
        scanf("%d", &x);
        if(x == password) admin();//管理者モード
        if(x == -1){//exit
            printf("Until next time!\n");
            break;
        }
        if(1 <= x <= beverage_len){
            //商品を選んでいるはず、続きをかく
        }
    }
}