#include <bits/stdc++.h>
using namespace std;
#define MAX 1400

struct Rectangle{
    // indexの地点の高さ
    int height;
    // 始点のX
    int pos;
};

// buf = Tの一行の配列
// size = Tの一行のサイズ
int getLargestRectangle(int size,int buf[]){
    // stackとして長方形を保存
    stack<Rectangle> s;
    int maxV = 0;
    // 配列の最後を0にすることで、範囲外後に最大面積を計算するようにする
    buf[size] = 0;
    // stoperまで回す
    for(int i = 0;i <= size;++i){
        Rectangle rect;
        // 高さ代入
        rect.height = buf[i];
        // 横の位置は計算を始める時点の位置
        rect.pos = i;
        // stack空ならば追加
        if(s.empty()){
            s.push(rect);
        }
        else{
            // stackのトップにあるrectの高さより高い場合
            if(s.top().height < rect.height){
                s.push(rect);
            }
            // stackのトップにあるrectの高さよりも低い場合(保存してあった最大の高さが無効になるので、無効になる高さの面積を計算する必要がある)
            else if(s.top().height > rect.height){
                // 新しく積むrectの幅を出すために保存しておく。
                int targetX = i;
                // スタックに入っているrectが対象のrectの高さ以上の場合最大面積を計算する
                while(!s.empty() && s.top().height >= rect.height){
                    Rectangle pre = s.top();
                    s.pop();
                    // 面積を計算する
                    int area = pre.height * (i - pre.pos);
                    maxV = max(maxV,area);
                    // 始点Xを入れ替える(stackに積むrectの高さは取り出したrectの高さよりも低いので、取り出した地点が、長方形を計算する際のX座標になる)
                    targetX = pre.pos;
                }
                rect.pos = targetX;
                s.push(rect);
            }
        }
    }
    return maxV;
}

int H,W;
// タイル情報を2次元で保存0:綺麗なタイル,1:汚れたタイル
int tiles[MAX][MAX];
// 高さを格納する2次元配列
int T[MAX][MAX];

int getLargestRectangle(){
    // 各々の地点における高さを格納するプロセス
    for(int j = 0;j < W;++j){
        for(int i = 0;i < H;++i){
            // 汚れたタイル
            if(tiles[i][j]){
                T[i][j] = 0;
            }
            else{
                // 対象のindex地点の高さを格納する
                // 上の地点 + 1の高さになる
                T[i][j] = (i > 0) ? T[i - 1][j] + 1 : 1;    
            }
        }
    }
    // 最大面積保存用
    int maxV = 0;
    // 最大高さ分回す
    for(int i = 0;i < H;++i){
        maxV = max(maxV,getLargestRectangle(W,T[i]));
    }
    return maxV;
}

int main(){
    scanf("%d %d",&H,&W);
    for(int i = 0;i < H;++i){
        for(int j = 0;j < W;++j){
            char c; cin >> c;
            if(c == '.'){
                tiles[i][j] = 0;
            }else{
                tiles[i][j] = 1;
            }
        }
    }
    printf("%d\n",getLargestRectangle());
}