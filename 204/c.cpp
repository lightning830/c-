#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);//有向グラフだから片方のみ
        // g[b].push_back(a);
    }
    int ans = 0;
    ans += n;//自分の町には移動できる
    rep(xx, g.size()){//各町をスタート地点として考えていく
        vector<int> dist(n, INF);
        dist[xx] = 0;
        queue<ll> q;
        q.push(xx);
        while(!q.empty()){
            int tmp = q.front(); q.pop();//tmp町なう
            auto update = [&](int i, int j){//jからiに行くとき
                if(dist[i] != INF) return;//すでに訪れている場合はなし
                dist[i] = j;//初めての時はjから来たことを書く
                q.push(i);//次の街をpush
                ans++;//訪れた町を加算
            };
            rep(i, g[tmp].size()){
                update(g[tmp][i], tmp);
            }
        }
    }


    cout << ans << endl;

    return 0;
}