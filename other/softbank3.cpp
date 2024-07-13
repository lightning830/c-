#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define FORA(i,I) for(const auto& i:I)
#define ALL(x) x.begin(),x.end() 
#define pb push_back


int main() {
    string s; cin >> s;
    // 優先度付きキュー昇順
    // 前半と後半に分割してソート、その後結合
    priority_queue<char, std::vector<char>, std::greater<char>> a,b;
    rep(i, s.size()){
        if(i%2==0) a.push(s[i]);
        else b.push(s[i]);
    }
    V<char> ans;
    while(1){
        bool finish = false;
        if(!a.empty()){
            finish = true;
            ans.pb(a.top()); a.pop();
        } 
        if(!b.empty()){
            finish = true;
            ans.pb(b.top()); b.pop();
        } 
        if(!finish) break;
    }
    FORA(i, ans) cout << i;
    cout << endl;
    
    return 0;
}