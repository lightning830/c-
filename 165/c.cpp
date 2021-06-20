#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int n, m, q;
int ans = 0;
vector<int> a, b, c, d;

int main() {
    cin >> n >> m >> q;
    a = b = c = d = vector<int>(q);
    rep(i, q){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    void dfs(vector<int> A);
    dfs(vector<int>(1,1));
    cout << ans << endl;
    return 0;

}

void dfs(vector<int> A){
    if(A.size() == n+1){
        int now = 0;
        rep(i, q){
            if(A[b[i]] - A[a[i]] == c[i]) now += d[i];
        }
        ans = max(ans, now);
        return;
    }
    A.push_back(A.back());
    // rep(i, A.size()){
    //     cout << A[i] << " ";
    // }
    // cout << endl;
    while(A.back() <= m){
        dfs(A);
        A.back()++;
    }
}