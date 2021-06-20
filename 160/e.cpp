#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    int p[a], q[b], r[c];
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];

    sort(p, p + a);
    sort(q, q + b);
    sort(r, r + c, greater<int>());

    int ans = 0;
    while(1){
        bool check = false;
        int i = 0;
        if(p[i] == 0){
            while(p[i] != 0) i++; 
        }

        int j = 0;
        if(q[j] == 0){
            while(q[j] != 0) j++; 
        }

        int k = 0;
        if(r[k] == 0){
            while(r[k] != 0) k++; 
        }

        if(p[i] > q[j]){
            q[j] = 0;
            ans += r[k];
            r[k] = 0;
        }else[
            p[i] = 0;
            ans += r[k];
            r[k] = 0;
        ]



    }
}