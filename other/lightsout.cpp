#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;

static int mainboard[5][5];
// {
//     {0,0,0,0,0},
//     {0,0,0,0,0},
//     {1,0,1,0,1},
//     {1,0,1,0,1},
//     {0,1,1,1,0}
// };


void print(const int (*board)[5]){
    rep(i,5){
        rep(j,5){
            cout << board[i][j];
        } 
        cout << endl;
    }
}

void put(int y, int x, int (*board)[5]){
    auto update = [&](int i, int j){
        board[i][j] = (board[i][j]+1)%2;
    };
    update(y,x);
    if(x-1 < 0){
        if(y-1 < 0){//左上
            update(y+1, x); update(y, x+1);
        }else if(y+1 >= 5){//左下
            update(y, x+1); update(y-1, x);
        }else{//左端
            update(y, x+1); update(y-1, x); update(y+1, x);
        }
    }else if(x+1 >= 5){
        if(y-1 < 0){//右上
            update(y, x-1); update(y+1, x);
        }else if(y+1 >= 5){//右下
            update(y-1, x); update(y, x-1);
        }else{//右端
            update(y-1, x); update(y, x-1); update(y+1, x);
        }
    }else{
        if(y-1 < 0){
            update(y, x+1); update(y, x-1); update(y+1, x);
        }else if(y+1 >= 5){
            update(y-1, x); update(y, x+1); update(y, x-1);
        }else{
            update(y, x+1); update(y-1, x); update(y, x-1); update(y+1, x);
        }
    }
}

int binary(int bina){
    int binary = 0;
    int base = 1;
    while(bina>0){
        binary += ( bina % 2 ) * base;
        bina = bina / 2;
        base = base * 10;
    }
    return binary;
}

int main() {
    vector<vector<P>> ans;
    int board[5][5];
    cout << "LightsOut program started\n" <<  "input 5x5 LightsOut\n";
    rep(i,5)rep(j,5){
        cin >> mainboard[i][j];
    }
    rep(n, 32){
        vector<P> temp;
        rep(i, 5)rep(j, 5) board[i][j] = mainboard[i][j];
        int bina = binary(n);
        int bina2[5] = {0};
        rep(i, 5){
            bina2[i] = bina % 10;
            bina /= 10;
        }

        // cout << "start" << endl;
        // print(board);

        rep(i, 5){
            if(bina2[i]){
                put(0, i, board);
                temp.push_back(P(0, i));
                // cout << "put(" << 1 << "," << i+1 << ")" << endl;
            }
        }

        //上から順に
        for(int i = 1; i < 5; i++){
            rep(j, 5){
                if(board[i-1][j] == 1) {
                    put(i, j, board);
                    temp.push_back(P(i, j));
                    // cout << "put(" << i+1 << "," << j+1 << ")" << endl;
                    // print(board);
                }
            }
        }
        bool check = true;
        rep(i, 5)rep(j, 5){
            if(board[i][j] != 0) check = false;
        }
        if(check){
            // cout << "CLEAR" << endl;
            ans.push_back(temp);
        }else{
            // cout << "FALSE.. go next" << endl;
        }
        // cout << endl;


    }

    if(ans.empty()){
        cout << "FALSE" << endl;
    }else{
        int min = 100100100;
        vector<P> best;
        for(auto&& u: ans){
            if(min > u.size()){
                min = u.size();
                best = u;
            }
        }
        for(auto&& u: best){
            cout << "put(" << u.first+1 << "," << u.second+1 << ")" << endl;
        }
    }
    
    cout << "enter something, and finish this program.\n";
    int a; cin >> a;

    return 0;
}