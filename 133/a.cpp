#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    if(a*n > b) cout << b << endl;
    else cout << a*n << endl;

    return 0;
}