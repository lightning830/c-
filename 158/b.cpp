#include<iostream>
#include<string.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    ll count = 0;
    count += n/(a+b) * a;
    ll mod = n%(a+b);
    if(mod > 0){
        if(a > mod) count += mod;
        else count += a;
    }
    cout << count << endl;
}