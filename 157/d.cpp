// UnionFind木
#include<iostream>
#include<vector>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct UnionFind
{
    vector<int> d;
    UnionFind(int n = 0): d(n, -1){}
    int find(int x){//根にいる人を返す関数<0
        if(d[x] < 0) return x; //根にいる人
        return d[x] = find(d[x]);
    }

    bool unite(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return false;
        if(d[x] > d[y]) swap(x, y);//xが小さいなら。
        //dはつながっている人が格納されていて、
        //-なら自分含めた頂点数でその人が根。
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y){return find(x) == find(y);}
    int size(int x){return -d[find(x)];}
};

int deg[1000005];
vector<int> to[1000005];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    UnionFind uf(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        deg[a]++;//友達の数
        deg[b]++;
        uf.unite(a, b);    
    }
    rep(i, k){
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    rep(i, n){
        int ans = uf.size(i)-1-deg[i];
        for(int u : to[i]){
            if(uf.same(i, u)) ans--;
        }
        printf("%d%c", ans, i==n-1?'\n':' ');
    }
    return 0;
}
