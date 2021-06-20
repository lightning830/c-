#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int a, b; cin >> a >> b;
    if(a - 2*b <= 0) cout << 0 << endl;
    else cout << a - 2*b << endl;

    return 0;
}