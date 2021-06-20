#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    map<int, int> memo;
    int n,q;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
        memo[a[i]]++;
    } 
    // for(auto& a: memo){
    //     cout << a.second;
    // }
    // cout << endl;
    cin >> q;
    int x,y;
    rep(i, q){
        cin >> x >> y;
        // cout << "mw" << memo[x] << endl;
        sum += memo[x]*(y-x);
        memo[y] += memo[x];
        memo.erase(x);
        cout << sum << endl;
    }




    return 0;
}