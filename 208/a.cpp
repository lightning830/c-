#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1e18;

int main() {
    int a, b;
    cin >> a >> b;
    int sum = 6 * a;
    if(sum >= b && a <= b) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}