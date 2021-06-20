#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin >> n;
    rep(i, n){
        int a;
        cin >> a;
        if(i < n-1){
            cout << a << ",";
        }else{
            cout << a << endl;
        }
    }
}