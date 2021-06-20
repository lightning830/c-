#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n; cin >> n;
    int now = 1000;
    for(int i = 1;;i++){
        if(n <= now) break;
        now += 1000;
    }
    cout << now - n << endl;

    return 0;
}