#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n;
    string s;
    cin >> n >> s;
    rep(i, s.size()){
        if(s[i] == s[i+1]) n--;
    }
    cout << n << endl;

    return 0;
}