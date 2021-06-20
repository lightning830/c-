#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int k, n;
    cin >> k >> n;
    int a[n];
    rep(i, n) cin >> a[i];

    int max = -1;
    int memo;
    rep(i, n-1){
        int d = a[i+1]-a[i];
        if(d > max){
            max = d;
            memo = i;
        }
    }
    if(a[0]+(k-a[n-1]) > max){
        // cout << a[0]+(k-a[n-1]) << endl;
        max = a[0]+(k-a[n-1]);
        memo = n-1;
    }
    // cout << memo << endl;
    // cout << n-1 << endl;
    if(memo == n-1){
        int min = 10000000;
        int max = -1;

        rep(i, n){
            if(max < a[i]) max = a[i];
            if(min > a[i]) min = a[i];
        }

        cout << max - min << endl;
    }else{
        int temp = k-a[memo+1];
        cout << a[memo] + temp;
    }
    




}