#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

ll d(ll n){
    return log10(n)+1;
}

int main() {
    ll a, b, x;
    cin >> a >> b >> x;
    ll left = 0; ll right = 1e9;
    ll mid;
    while(left < right){
        mid = (left+right)/2;
        ll num = a*mid + b*d(mid);
        // cout << num << endl;
        if(x < num){
            // cout << mid << "a" << endl;
            right = mid;
        }
        if(x > num){
            // cout << mid << "b" << endl;
            left = mid + 1;
        }
        if(x == num){
            // cout << mid << "c" << endl;
            break;
        }
    }
    mid-=1;
    ll num = a*mid + b*d(mid);
    while(1){
        num = a*(mid+1) + b*d(mid+1);
        if(num > x) break;
        if(mid+1 <= 1e9){
            mid++;
        }else break;
        // cout << "mid" << mid << endl;
        // cout << "x = " << x << endl;
        // cout << num << endl;
    }

    cout << mid << endl;

}