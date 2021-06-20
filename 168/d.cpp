#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    queue<int> q;
    int INF = 1001001001;
    vector<int> dist(n, INF);
    q.push(0);
    // int now = 1;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        auto update = [&](int i, int j){
            if(dist[i] != INF) return;
            dist[i] = j;
            q.push(i);
        };
        rep(i, g[tmp].size()){
            update(g[tmp][i], tmp);
        }
    }
    bool check = true;
    rep(i, n){
        if(dist[i] == INF) check = false;
    }
    if(!check){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for(int i = 1; i < n; i++){
        cout << dist[i]+1 << endl;
    }

    return 0;
}