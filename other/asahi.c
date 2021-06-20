#include<stdio.h>
#include<stdlib.h>//mallocで使う
#include<string.h>//strcmpとか
#include<stdbool.h>//bool
// #include<sys/time.h>
#define HASHSIZE 17

struct match_score
{
    /* data */
    int year;
    int month;
    int day;
    int home_score;
    int away_score;
    struct match_score *next;
};

struct match
{
    /* data */
    char *home;
    char *away;
    struct match_score *r;
    struct match *next;
};
struct match *hashtable[20];

//確認用
void print(struct match *ptr){
    while(ptr != NULL){
        printf("%s %s %d %d\n", ptr->home, ptr->away, ptr->r->home_score, ptr->r->away_score);
        struct match_score *p; p = ptr->r;
        int n = 0;
        while(p != NULL){
            n++;
            p = p->next;
        }
        printf("%d\n", n);
        ptr = ptr->next;
    }
}

//確認用
void print2(){
    struct match *ptr = hashtable[0];
    while(ptr != NULL){
        printf("%s %s %d %d\n", ptr->home, ptr->away, ptr->r->home_score, ptr->r->away_score);
        ptr = ptr->next;
    }
}

void dist(){
    for(int i = 0; i < HASHSIZE; i++){//ハッシュテーブルそれぞれに行う
        int n = 0;
        struct match *p = hashtable[i];//そのハッシュテーブルを指すポインタ
        while(p != NULL){//ハッシュテーブルの数をカウント
            n++;
            p = p->next;
        }
        printf("TABLE[%d]:%d\n", i, n);//出力
    }
}

int hash(char* str){
    int n = 0;
    while(*str != '\0'){//strのasciiコードの和を計算
        n += *str;
        str++;
    }
    return abs(n%HASHSIZE);//modをとり値をhashsizeに収める
}

void record(char* home, char* away){
    int n = hash(home);//ハッシュ値
    struct match *ptr; ptr = hashtable[n];//ハッシュテーブルのポインタ
    bool flag = false;
    while(ptr != NULL){//その試合を探す
        if(strcmp(ptr->home, home) == 0 && strcmp(ptr->away, away) == 0){
            flag = true;
            break;
        }
        ptr = ptr->next;
    }
    int sum = 0, w = 0, l = 0, d = 0;
    if(flag){//あったとき
        struct match_score *ptr2; ptr2 = ptr->r;//ハッシュテーブル中でいま指すポインタのr(match_score)のポインタ
        while(ptr2 != NULL){//試合数や勝敗カウント
            sum++;
            if(ptr2->home_score > ptr2->away_score) w++;
            if(ptr2->home_score < ptr2->away_score) l++;
            if(ptr2->home_score == ptr2->away_score) d++;
            ptr2 = ptr2->next;
        }
    }

    //勝敗
    printf("%s(HOME) vs %s(AWAY): %d games. (win:%d lose:%d draw:%d)\n", home, away, sum, w, l, d);

}

void record_year(char* home, char* away, int year){
    int n = hash(home);
    struct match *ptr; ptr = hashtable[n];
    bool flag = false;
    while(ptr != NULL){
        if(strcmp(ptr->home, home) == 0 && strcmp(ptr->away, away) == 0){
            flag = true;
            break;
        }
        ptr = ptr->next;
    }
    int sum = 0, w = 0, l = 0, d = 0;
    if(flag){
        struct match_score *ptr2; ptr2 = ptr->r;
        while(ptr2 != NULL){
            if(year == ptr2->year){//そのyearのときのみカウントする、他はrecordと同じ
                sum++;
                if(ptr2->home_score > ptr2->away_score) w++;
                if(ptr2->home_score < ptr2->away_score) l++;
                if(ptr2->home_score == ptr2->away_score) d++;
            }
            ptr2 = ptr2->next;
        }
    }

    printf("[%d]: %s(HOME) vs %s(AWAY): %d games. (win:%d lose:%d draw:%d)\n", year, home, away, sum, w, l, d);

}


void add(int year, int month, int day, char* home_team, int home_score, int away_score, char* away_team){
    struct match *tmp;//ハッシュテーブルに入れるmatchポインタ
    struct match_score *tmp1;//matchに入れるmatch_scoreのポインタ
    tmp = malloc(sizeof(struct match));//メモリ確保
    tmp1 = malloc(sizeof(struct match_score));

    tmp->home = (char*)malloc(sizeof(char)*128);//メモリ確保
    tmp->away = (char*)malloc(sizeof(char)*128);

    strcpy(tmp->home, home_team);//home_teamをtmpのhomeにコピー
    strcpy(tmp->away, away_team);
    tmp1->year = year;//tmp1のyearにyearを代入
    tmp1->month = month;
    tmp1->day = day;
    tmp1->home_score = home_score;
    tmp1->away_score = away_score;

    int n = hash(home_team);//どのハッシュテーブルに入れるか

    struct match *p; p = hashtable[n];//入れるハッシュテーブルのポインタ
    bool flag = false;//もうその試合があるかどうか

    while(p != NULL){
        if(strcmp(p->home, home_team) == 0 && strcmp(p->away, away_team) == 0){//その試合を見つけた場合
            flag = true;
            tmp1->next = p->r;//tmp1の次に、pのr(match_score)につなげる
            p->r = tmp1;//pのrにtmp1をつなげる
            //これで"pのr"の先頭にtmp1をつなげていることになる(ポインタの付け替え)
            break;
        }
        p = p->next;
    }
    if(!flag){//なかった場合
        tmp1->next = NULL;//tmp1の次にはなにもない
        tmp->r = tmp1;//tmpとtmp1で合体
        tmp->next = hashtable[n];//ここもポインタの付け替えで、今さすハッシュテーブルの先頭にtmpをつなげる
        hashtable[n] = tmp;
    }


    
}


int main(){
    //書いてあったのをコピペしただけ
    char home_team[256], away_team[256];
    int home_score, away_score;
    int year, month, day, i, f;
    const char *filename = "jleague.txt";
    FILE *fp;

    for(i=0; i < HASHSIZE; i++){
        hashtable[i]=NULL;
    }
    // struct timeval t1, t2;


    fp = fopen(filename,"r");
    while((f = fscanf(fp,"%d %d %d %s %d %d %s",&year,&month,&day,home_team,&home_score,&away_score,away_team))!=EOF){
        add(year,month,day,home_team,home_score,away_score,away_team);
    }
    // print(m);
    // print2();
    printf("--HASHSIZE: %d--\n", HASHSIZE);
    dist();
    // gettimeofday(&t1, NULL);
    record("Urawa_Red_Diamonds","Kashiwa_Reysol");
    record("Kashiwa_Reysol","Urawa_Red_Diamonds");
    record("Kashima_Antlers","Gamba_Osaka");
    record_year("Kashima_Antlers","Gamba_Osaka",2007);
    record("apex","ButtlePass");
    // gettimeofday(&t2, NULL);
    // printf("time = %lf\n", (t2.tv_sec - t1.tv_sec)+(t2.tv_usec - t1.tv_usec)*1.0E-6);

}

