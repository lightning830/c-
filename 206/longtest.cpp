#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n = 1000000;
    ll m = n * n;
    //n*nの時点ではint型なので、エラー
    //mに代入するまでllではない!!
    cout << m << endl;

    return 0;
}