#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int n,w;
vector<P> item;

int rec(int i, int j){
    int res;
    if(i == n) res = 0;
    else if(j - item[i].first < 0) res = rec(i+1, j);
    else{
        res = max(rec(i+1, j), rec(i+1, j-item[i].first) + item[i].second);
    }
    return res;
}

int main() {
    cin >> n >> w;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        item.push_back(P(a,b));
    } 
    cout << rec(0, w) << endl;

}