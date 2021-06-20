#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    //掃き出し法つかいます
    int n = 5; //5*5だから。
    double a[n][n];//入力する行列
    cout << "please input" << endl;
    rep(i, n)rep(j, n) cin >> a[i][j]; //入力

    double b[n][n];//掃き出し法の左側の単位行列
    rep(i, n)rep(j, n){//単位行列に初期化
        if(i == j) b[i][j] = 1;
        else b[i][j] = 0;
    }

    //ここから掃き出し法

    rep(j, n){//各列でそれぞれ単位行列を作っていく

        //対角成分を1にしていく
        double to1 = 1 / a[j][j];//かけると対角成分が1になる数
        rep(k, n){//j行目をto1倍する
            a[j][k] *= to1;
            b[j][k] *= to1;
        }

        //対角成分以外を0にする
        rep(i, n){//各行
            if(i == j) continue;//対角成分の行は1でいいのでパスする
            double to0 = -a[i][j];//対角成分(=1)になにをかけて足せば0になるか
            rep(k, n){//i行目からj行目*to0を足す
                a[i][k] += a[j][k]*to0;
                b[i][k] += b[j][k]*to0;
            }
        }
    
    }

    rep(i, n){//出力
        rep(j, n) cout << b[i][j] << " ";
        cout << endl;
    }
}