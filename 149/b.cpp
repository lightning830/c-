#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;

int main(){
    ll a, b, k;
    cin >> a >> b >> k;
    if((a-k) < 0){
        k -= a;
        a = 0;
        b -= k;
        if(b < 0) b = 0;
    }else{
        a -= k;
    }
    cout << a << " " << b << endl;
}