#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main(){
    int k; cin >> k;
    queue<ll> que;
    for(int i = 1; i <= 9; i++){
        que.push(i);
    }
    rep(i, k-1){
        ll x = que.front();
        que.pop();
        for(int j = -1; j <= 1; j++){
            ll d = x%10;
            d += j;
            if(d < 0 || d > 9) continue;
            que.push(x*10+d);
        }
    }
    cout << que.front() << endl;
    // while(!que.empty()){
    //     cout << que.front() << " ";
    //     que.pop();
    // }
}
