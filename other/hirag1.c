#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<stdbool.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define n 8

const int INF = 1001001001;
int board[n][n];//yoko, tate

//1: white, -1:black

void sleep(int i){
    clock_t g;
    g = i * CLOCKS_PER_SEC + clock();
    while(g > clock()){}
}

void print(){
    rep(y, n){
        rep(x, n){
            if(board[x][y] == 1) printf("o ");
            else if(board[x][y] == -1) printf("x ");
            else printf("- ");
        }
        printf("\n");
    }
}

bool canPut1(int x, int y, int vx, int vy, int color){
    x += vx; y += vy;
    if(x < 0 || x >= 8 || y < 0 || y >= 8) return false;
    if(board[x][y] == color) return false;
    if(board[x][y] == 0) return false;

    x += vx; y += vy;
    while(x >= 0 && x < 8 && y >= 0 && y < 8){
        if(board[x][y] == 0) return false;
        if(board[x][y] == color) return true;
        x += vx; y += vy;
    }
    return false;
}

bool canPut(int x, int y, int color){
    if(x >= 8 || y >= 8) return false;
    if(board[x][y] != 0) return false;
    if(canPut1(x, y, 1, 0, color)) return true;
    if(canPut1(x, y, 0, 1, color)) return true;
    if(canPut1(x, y, -1, 0, color)) return true;
    if(canPut1(x, y, 0, -1, color)) return true;
    if(canPut1(x, y, 1, 1, color)) return true;
    if(canPut1(x, y, -1, -1, color)) return true;
    if(canPut1(x, y, 1, -1, color)) return true;
    if(canPut1(x, y, -1, 1, color)) return true;
    return false;
}
void update(int x, int y, int dx, int dy, int color){
    x += dx; y += dy;
    while(board[x][y] != color){
        board[x][y] = color;
        x += dx; y += dy;
    }
}


void put(int x, int y, int color){
    int dx = 0, dy = 0;
    board[x][y] = color;
    if(canPut1(x, y, 1, 0, color)){dx = 1; dy = 0; update(x, y, dx, dy, color);}
    if(canPut1(x, y, 0, 1, color)){dx = 0; dy = 1; update(x, y, dx, dy, color);}
    if(canPut1(x, y, -1, 0, color)){dx = -1; dy = 0; update(x, y, dx, dy, color);}
    if(canPut1(x, y, 0, -1, color)){dx = 0; dy = -1; update(x, y, dx, dy, color);}
    if(canPut1(x, y, 1, 1, color)){dx = 1; dy = 1; update(x, y, dx, dy, color);}
    if(canPut1(x, y, -1, -1, color)){dx = -1; dy = -1; update(x, y, dx, dy, color);}
    if(canPut1(x, y, 1, -1, color)){dx = 1; dy = -1; update(x, y, dx, dy, color);}
    if(canPut1(x, y, -1, 1, color)){dx = -1; dy = 1; update(x, y, dx, dy, color);}
}

void pturn(){
    printf("player1 turn(white)\n");
    printf("select place to put. if you pass, input -1\n");
    while(1){
        int x, y;
        scanf("%d", &x);
        if(x == -1) return;
        scanf("%d", &y);
        if(canPut(x-1, y-1, 1)){
            put(x-1, y-1, 1);
            break;
        } 
        else printf("%d,%d you cannot put. input again\n", x, y);
    }

}

void eturn(){
    printf("player2 turn(black)\n");
    printf("select place to put. if you pass, input -1\n");
    while(1){
        int x, y;
        scanf("%d", &x);
        if(x == -1) return;
        scanf("%d", &y);
        if(canPut(x-1, y-1, -1)){
            put(x-1, y-1, -1);
            break;
        } 
        else printf("%d,%d you cannot put. input again\n", x, y);
    }
    
}

void result(){
    int player = 0, enemy = 0;
    rep(y, n)rep(x, n){
        if(board[x][y] == 1) player++;
        if(board[x][y] == -1) enemy++;
    }
    printf("player->%d enemy->%d\n", player, enemy);
    if(player > enemy) printf("player win\n");
    else if(player < enemy) printf("player2 win\n");
    else printf("draw\n");
}

int main() {
    int turn = 1;
    board[3][3] = board[4][4] = 1;
    board[4][3] = board[3][4] = -1;
    printf("let's osero\n");
    print();
    while(1){
        if(turn == 1){
            pturn(); turn = -1;
        } 
        else if(turn == -1){
            eturn(); turn = 1;
        }
        sleep(1);
        system("cls");
        print();
        bool endflag = false, endflag2 = false;
        rep(y, n)rep(x, n){
            if(board[x][y] == 0) endflag = true;
            if(canPut(x, y, 1)) endflag2 = true;
            if(canPut(x, y, -1)) endflag2 = true;
        }
        if(!endflag || !endflag2) break;
    }
    // sleep(1);

    result();

    return 0;
}
