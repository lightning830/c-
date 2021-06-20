#include<iostream>
#include<vector>
#include<time.h>
#include<conio.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

const int INF = 1001001001;
const int n = 8;
vector<vector<int>> board(n, vector<int>(n, 0));//yoko, tate
const int eval[n][n] ={
    {30, -12, 0, -1, -1, 0, -12, 30},
    {-12, -15, -3, -3, -3, -15, -12},
    {0, -3, 0, -1, -1, 0, -3, 0},
    {-1, -3, -1, -1, -1, -1, -3, -1},
    {-1, -3, -1, -1, -1, -1, -3, -1},
    {0, -3, 0, -1, -1, 0, -3, 0},
    {-12, -15, -3, -3, -3, -15, -12},
    {30, -12, 0, -1, -1, 0, -12, 30}
};

//1: white, -1:black

void sleep(int i){
    clock_t g;
    g = i * CLOCKS_PER_SEC + clock();
    while(g > clock()){}
}

void print(){
    rep(y, n){
        rep(x, n){
            if(board[x][y] == 1) cout << "o ";
            else if(board[x][y] == -1) cout << "x ";
            else cout << "- " ;
        }
        cout << endl;
    }
}

bool canPut(int x, int y, int vx, int vy, int color){
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
    if(canPut(x, y, 1, 0, color)) return true;
    if(canPut(x, y, 0, 1, color)) return true;
    if(canPut(x, y, -1, 0, color)) return true;
    if(canPut(x, y, 0, -1, color)) return true;
    if(canPut(x, y, 1, 1, color)) return true;
    if(canPut(x, y, -1, -1, color)) return true;
    if(canPut(x, y, 1, -1, color)) return true;
    if(canPut(x, y, -1, 1, color)) return true;
    return false;
}


void put(int x, int y, int color){
    int dx = 0, dy = 0;
    board[x][y] = color;
    auto update = [&](){
        int xx = x; int yy = y;
        xx += dx; yy += dy;
        while(board[xx][yy] != color){
            board[xx][yy] = color;
            xx += dx; yy += dy;
            // cout << xx << " " << yy << endl;
        }
    };
    if(canPut(x, y, 1, 0, color)){dx = 1; dy = 0; update();}
    if(canPut(x, y, 0, 1, color)){dx = 0; dy = 1; update();}
    if(canPut(x, y, -1, 0, color)){dx = -1; dy = 0; update();}
    if(canPut(x, y, 0, -1, color)){dx = 0; dy = -1; update();}
    if(canPut(x, y, 1, 1, color)){dx = 1; dy = 1; update();}
    if(canPut(x, y, -1, -1, color)){dx = -1; dy = -1; update();}
    if(canPut(x, y, 1, -1, color)){dx = 1; dy = -1; update();}
    if(canPut(x, y, -1, 1, color)){dx = -1; dy = 1; update();}
}

void pturn(){
    cout << "your turn" << endl
    << "select place to put. if you pass, input -1" << endl;
    while(1){
        int x, y;
        cin >> x;
        if(x == -1) return;
        cin >> y;
        if(canPut(x-1, y-1, 1)){
            put(x-1, y-1, 1);
            break;
        } 
        else cout << x << "," << y << " you cannot put. input again" << endl;
    }

}

void eturn(){
    cout << "enemy turn" << endl;
    int xx = -1, yy = -1;
    int max = -INF;
    rep(y, n)rep(x, n){
        if(max < eval[x][y] && canPut(x, y, -1)){
            xx = x; yy = y;
            max = eval[x][y];
        }
    }
    cout << "put(" << xx+1 << "," << yy+1 << ")" << endl;
    if(xx == -1 && yy == -1) return;
    put(xx, yy, -1);
    
}

void result(){
    int player = 0, enemy = 0;
    rep(y, n)rep(x, n){
        if(board[x][y] == 1) player++;
        if(board[x][y] == -1) enemy++;
    }
    cout << "player->" << player << " " << "enemy->" << enemy << endl;
    if(player > enemy) cout << "you win" << endl;
    else if(player < enemy) cout << "enemy win" << endl;
    else cout << "draw" << endl;
}

int main() {
    int turn = 1;
    board[3][3] = board[4][4] = 1;
    board[4][3] = board[3][4] = -1;
    cout << "Let's osero." << endl;
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
    sleep(1);

    result();

    return 0;
}
