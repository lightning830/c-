#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;

int main(){
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;

    int max = 0;
    rep(i, k){
        vector<char> a;
        for(int j = i; j < n; j+=k){
            a.push_back(t[j]);
        }
        // rep(j, a.size()) cout << a[j];
        // cout << endl;
        if(a[0] == 'r') max += p;
        if(a[0] == 's') max += r;
        if(a[0] == 'p') max += s;
        for(int j = 1; j < a.size(); j++){
            if(a[j] == a[j-1]){
                a[j] = 'a';
            }else{
                if(a[j] == 'r') max += p;
                if(a[j] == 's') max += r;
                if(a[j] == 'p') max += s;
            }
        }
    }
    cout << max << endl;
}