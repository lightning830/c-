#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n;
    char s[1000];
    char t[1000];
    cin >> n >> s >> t;
    string ans = "";
    rep(i, n){
        ans.push_back(s[i]);
        ans.push_back(t[i]);
    }
    cout << ans << endl;

}