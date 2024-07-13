#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define FORA(i,I) for(const auto& i:I)
#define ALL(x) x.begin(),x.end()

size_t one_char = 3;//1文字3バイト

int main() {
    int n; cin >> n;
    map<string, set<string>> g;//最初と最後の文字の有向グラフ
    map<string, int> dist;//文字までの最小移動回数

    rep(i, n){//グラフ作成
        string s; cin >> s;
        string start = s.substr(0,one_char);
        string end = s.substr(s.size()-one_char,one_char);
        g[start].insert(end);
        dist[start] = 0;
    }

    //幅優先探索
    queue<string> q;
    q.push("り");
    while(!q.empty()){
        string now = q.front();
        q.pop();
        auto update = [&](string i, string j){//distを更新
            if(dist[i] != 0 || i == "り") return;//訪れていたら、またはスタートに戻るとき何もしない
            dist[i] = dist[j]+1;//移動回数メモ
            q.push(i);//次
        };
        FORA(i, g[now]){
            if(i == "ん"){//ん、が来た時点でしりとり終了
                cout << dist[now]+1 << endl;
                return 0;
            }
            update(i, now);
        }
    }
    cout << -1 << endl;

    
    return 0;
}