#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

map<string, int> memo;

int main() {
    int n;
    cin >> n;
    rep(i, n){
        string s;
        cin >> s;
        memo[s] += 1;
    }
    cout << memo.size() << endl;


}