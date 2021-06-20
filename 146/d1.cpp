#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

struct Edge{
    int to, id;//to:つながっている先 id:辺
};

int main() {
    int n;
    cin >> n;
    vector<vector<Edge>> g(n);
    vector<int> ans(n-1);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back((Edge){b, i});
        g[b].push_back((Edge){a, i});
    }
    queue<int> q;
    vector<int> used(n);//すでに調べてある点かどうか
    q.push(0);
    used[0] = 1;
    while(!q.empty()){
        int v = q.front(); q.pop();
        int c = -1;
        rep(i, g[v].size()){
            int u = g[v][i].to, ei = g[v][i].id;
            if(used[u]) c = ans[ei];//必ず一個あるはず
            //その点からつながっている点の中で,前の点が1つあるから

            //その時の辺の色を前の色とすればいい
        }
        int k = 1;
        rep(i, g[v].size()){
            int u = g[v][i].to, ei = g[v][i].id;
            if(used[u]) continue;
            if(k == c) k++;
            ans[ei] = k; k++;
            q.push(u);
            used[u] = 1;
        }
    }

    int mx = 0;
    rep(i, n) mx = max(mx, int(g[i].size()));
    cout << mx << endl;
    rep(i, n-1){
        cout << ans[i] << endl;
    }
    return 0;
}