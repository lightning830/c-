#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int fun(int x){
    int a = 0;
    for(int i = 1;;i++){
        a += i;
        if(a == x) return i;
        else if(x < a) return i-1;
    }
}

int main() {
    ll n; cin >> n;
    ll half = sqrt(n);
    int ans = 0;
    if(n == 1){
        cout << 0 << endl; return 0;
    }
    for(int i = 2; i <= half; i++){//素因数分解
        int a = 0;//iで何回割り切れるか
        while(n%i==0){
            a++;
            n /= i;
        }
        ans += fun(a);
    }
    if(n > 1) cout << ans+1 << endl;
    else cout << ans << endl;

    return 0;
}