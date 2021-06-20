#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

const int D = 80*160+10;
const int D2 = D*2;
using bs = bitset<D2>;

int a[100][100];
bs dp[90][90];

int main() {
    int h, w;
    cin >> h >> w;
    rep(i, h)rep(j, w){
        int x;
        cin >> x;
        a[i][j] = x;
    }
    rep(i, h)rep(j, w){
        int x;
        cin >> x;
        a[i][j] = abs(x-a[i][j]);
    }//最初は絶対値にする.あとで+や-を適当に付けてdpする

    //3,2,1,0,-1,-2
    //0,1,0,1, 1, 0 bit
    //合計値を2,0,-1にできる

    dp[0][0][D-a[0][0]] = 1;//dp[0][0]のbitsetのD-a[0][0]bit目,-a[0][0]が可能ということ
    dp[0][0][D+a[0][0]] = 1;
    rep(i, h)rep(j, w){
        //下移動
        if(i){//i != 0
            dp[i][j] |= dp[i-1][j]<<a[i][j];//たす
            dp[i][j] |= dp[i-1][j]>>a[i][j];//ひく
            //|で足す場合と引く場合の可能な数字を合わせられる
        }
        //右移動
        if(j){
            dp[i][j] |= dp[i][j-1]<<a[i][j];
            dp[i][j] |= dp[i][j-1]>>a[i][j];
        }
    }
    int ans = D2;
    rep(i, D2){
        if(dp[h-1][w-1][i]){
            ans = min(ans, abs(i-D));
        }
    }
    cout << ans << endl;

    return 0;
}