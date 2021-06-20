#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    // int n = 3;
    // double a[n][n] = {
    //     {1,3,2},
    //     {-1,0,1},
    //     {2,3,0}
    // };

    int n = 5; //5*5
    // double a[n][n] = {
    //     {1,0,2,0,1},
    //     {2,3,4,1,0},
    //     {1,0,3,3,2},
    //     {3,2,2,2,1},
    //     {1,1,1,0,1}
    // };

    double a[n][n];
    cout << "please input" << endl;
    rep(i, n)rep(j, n) cin >> a[i][j];

    double b[n][n];
    rep(i, n)rep(j, n){
        if(i == j) b[i][j] = 1;
        else b[i][j] = 0;
    }

    rep(j, n){
        double to1 = 1 / a[j][j];
        // cout << "to1 = " << to1 << endl;
        rep(k, n){
            a[j][k] *= to1;
            b[j][k] *= to1;
        }
        rep(i, n){
            if(i == j) continue;
            double to0 = -a[i][j];
            rep(k, n){
                a[i][k] += a[j][k]*to0;
                b[i][k] += b[j][k]*to0;
            }
        }
        // rep(i, n){
        //     rep(j, n) cout << a[i][j] << " ";
        //     cout << endl;
        // }
    
    }

    cout << "answer" << endl;
    rep(i, n){
        rep(j, n) cout << b[i][j] << " ";
        cout << endl;
    }
}