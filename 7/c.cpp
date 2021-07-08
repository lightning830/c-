#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1e18;

int main() {
    int r, c, sy, sx, gy, gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    vector<vector<int>> C(r, vector<int>(c));
    rep(i, r){
        string a; cin >> a;
        for(int k = 0; k < a.size(); k++){
            // cout << a[k] << endl;
            if(a[k] == '#') C[i][k] = -1;//壁
            else C[i][k] = INF;
        }

    }
    // rep(i, r){
    //     rep(j, c){
    //         cout << C[i][j];
    //     }
    //     cout << endl;
    // }
    queue<P> q;
    // vector<vector<int>> dist(r, vector<int>(c));
    q.push(P(sx, sy));
    int num = 0;
    while(!q.empty()){
        P tmp = q.front(); q.pop();
        
        P up = make_pair(tmp.first, tmp.second-1);
        P down = make_pair(tmp.first, tmp.second+1);
        P right = make_pair(tmp.first+1, tmp.second);
        P left = make_pair(tmp.first-1, tmp.second);
    }


    return 0;
}