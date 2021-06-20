#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    int h[n];
    vector<set<int>> tenbou(n);

    rep(i, n){
        cin >> h[i];
    }
    int a[m], b[m];
    rep(i, m){
        cin >> a[i] >> b[i];
        tenbou[a[i]-1].insert(b[i]-1);
        tenbou[b[i]-1].insert(a[i]-1);
    }

    int num = 0;
    rep(i, n){
        bool check = true;
        for(auto x: tenbou[i]){
            if(h[x] >= h[i]) check = false;
        }
        if(check){
            num++;
        }
    }
    cout << num << endl;


    
}