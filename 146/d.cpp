#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

struct Edge{
    int to, id;//to:つながっている先 id:辺
};

vector<vector<Edge>> g;
vector<int> ans;

void dfs(int v, int c = -1, int p = -1){//v:点 c:その点の前ですでに塗られている色 p:前の点
    int k = 1;
    rep(i, g[v].size()){
        int u = g[v][i].to, ei = g[v][i].id;
        if(u == p) continue;//前の点は無視
        if(k == c) k++;//前ですでに使われている色はパス
        ans[ei] = k; k++;//色を代入していく
        dfs(u, ans[ei], v);
    }
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    // ans = vector<int>(n-1);
    ans.resize(n-1);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back((Edge){b, i});
        g[b].push_back((Edge){a, i});
    }
    dfs(0);
    int mx = 0;
    rep(i, n) mx = max(mx, int(g[i].size()));
    cout << mx << endl;
    rep(i, n-1){
        cout << ans[i] << endl;
    }
    return 0;
}