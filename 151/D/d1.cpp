#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};
    // P p(2,4);
    // cout << p.first << endl;
    int h, w;
    cin >> h >> w;
    char s[h][w];
    rep(i, h)rep(j, w){
        cin >> s[i][j];
    }
    int ans = 0;

    rep(i, h)rep(j, w){
        // int i = 0, j = 0;
        // int step = 0;
        int mx = 0;
        if(s[i][j] == '#') continue;
        queue<P> q;//pair型
        vector<vector<int>> dist(h, vector<int>(w, -1));
        dist[i][j] = 0;
        q.push(P(i,j));
        while(!q.empty()){
            P tmp = q.front();
            q.pop();
            // step++;
            auto update = [&](int i, int j, int k){
                q.push(P(i, j));
                dist[i][j] = k;
                mx = max(mx, dist[i][j]);
            };

            rep(i, 4)rep(j, 4){
                int y = tmp.first + dx[i];
                int x = tmp.second + dy[i];
                if(y >= h || x >= w || y < 0 || x < 0) continue;
                if(s[y][x] == '#') continue;
                if(dist[y][x] != -1) continue;
                update(y, x, dist[tmp.first][tmp.second]+1);

            }
            // rep(i, h){
            //     rep(j, w){
            //         cout << dist[i][j] << " ";
            //     }
            //     cout << endl;

            // }
            // cout << endl;
        }

        ans = max(ans, mx);
    }
    cout << ans << endl;

    return 0;
}