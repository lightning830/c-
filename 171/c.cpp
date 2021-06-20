#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int digit(ll num){//桁数
    return log10(num)+1;
}

int main() {
    ll n; cin >> n;
    // ll ans = 0;
    // cout << digit(4109) << endl;
    ll num = 1;
    while(1){
        if(n - pow(26, num) < 0) break;
        n -= pow(26, num);
        if(n == 0){
            rep(i, num){
                cout << "z";
            }
            cout << endl;
            return 0;
        }
        num++;
    }
    num--;
    // cout << "num = " << num << endl;
    // cout << "n = " << n << endl;

    for(int i = num; i >= 0; i--){
        char moji = 'a';
        int a = 1;
        // cout << "dd" << endl;
        while(1){
            if(n - pow(26, i)*a <= 0){
                n -= pow(26, i)*(a-1);
                // cout << "n = " << n << endl;
                // cout << "a = " << a << endl;
                printf("%c", moji + a - 1);
                // cout << moji + a - 1;
                // cout << "aa" << endl;
                break;
            }
            a++;
            // cout << "cc" << endl;
        }

    }
    cout << endl;

    // cout << num << endl;


    return 0;
}