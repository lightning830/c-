#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int x[n], y[n];
    double sum = 0;
    rep(i, n){
        cin >> x[i] >> y[i];
    }
    rep(i, n)rep(j, n){
        if(i == j) continue;
        sum += sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
    }//左右逆のパターンが混同しているからあとで2で割る
    printf("%.10f", sum/n);//ここで割ってる

    return 0;
}