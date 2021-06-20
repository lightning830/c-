#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n; cin >> n;
    int a[9][9];
    for(int j = 1; j < 10; j++){
        for(int k = 1; k < 10; k++){
            a[j-1][k-1] = j*k;
            // cout << a[j-1][k-1] << endl;
        }
    }

    bool check = false;
    for(int j = 1; j < 10; j++){
        for(int k = 1; k < 10; k++){
            if(n == a[j-1][k-1]) check = true;
        }
    }

    cout << (check? "Yes": "No") << endl;
}