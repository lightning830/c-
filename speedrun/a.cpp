#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    int max = 0;
    rep(i, n){
        if(max < a[i]) max = a[i];
    }
    cout << max << endl;
}