#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main(){
    int n;
    string s;
    cin >> n >> s;
    ll r = 0, g = 0, b = 0;
    rep(i, n){
        if(s[i]=='R') r++; 
        if(s[i]=='G') g++;
        if(s[i]=='B') b++;
    }
    ll ans = r*g*b;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(j+j-i >= n) continue;
            if(s[i] != s[j] && s[i] != s[j+j-i] && s[j] != s[j+j-i]){
                ans--;
            }
        }
    }
    cout << ans << endl;
}
