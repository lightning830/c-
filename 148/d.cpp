#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    int num = 0;
    int search = 1;
    bool check = false;
    rep(i, n){
        if(a[i] == search){
            search++;
            check = true;
        }else{
            num++;
        }
    }
    cout << (!check? -1: num) << endl;

}