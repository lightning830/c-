#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin >> n;
    int num = 1;
    int a[n];
    int maxa[n];
    cin >> a[0]; maxa[0] = a[0];
    for(int i = 1; i < n; i++){
        cin >> a[i];
        if(maxa[i-1] < a[i]){
            maxa[i] = a[i];
        }else{
            maxa[i] = maxa[i-1];
        }
    }
    rep(i, n){
        if(i != 0){
            if(maxa[i-1] < a[i]){
                num++; 
                // cout << "now" << i << endl;
            } 
        }
    }
    cout << num << endl;

    // rep(i, n) cout << maxa[i] ;
    // cout << endl;
}