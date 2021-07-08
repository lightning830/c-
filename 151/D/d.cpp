// #include<iostream>
// #include<string>
// #include<vector>
// #include<queue>
// 幅優先探索
#include<bits/stdc++.h>
// #include<utility>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;

const int INF = 1001001001;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};//4方向

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int ans = 0;
    rep(si, h) rep(sj, w){//(si, sj)=start
        if(s[si][sj] == '#') continue;
        vector<vector<int>> dist(h, vector<int>(w, INF));
        queue<P> q;
        auto update = [&](int i, int j, int x){//&はスコープの外からでもアクセス可能
            if(dist[i][j] != INF) return;
            dist[i][j] = x;
            q.push(P(i, j)); //emplaceでもよし 
        };//周りを開いたあと値代入とqueueに追加する関数

        update(si, sj, 0);
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second; q.pop();
            rep(dir, 4){
                int ni = i + di[dir], nj = j + dj[dir];
                if(ni < 0 | ni >= h | nj < 0 | nj >= w) continue;
                if(s[ni][nj] == '#') continue;
                update(ni, nj, dist[i][j]+1);
            }
        }
        rep(i, h)rep(j, w){
            if(dist[i][j] == INF) continue;
            ans = max(ans, dist[i][j]+1);
        }
    }
    cout << ans << endl;
    return 0;
}