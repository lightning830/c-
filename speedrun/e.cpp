#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin >> n;
    int num = 0;
    bool check = false;
    rep(i, n){
        int a;
        cin >> a;
        if(a == 1){
            check = true;
            num++;
        }
        if(!check) num++;
    }
    cout << num << endl;
}