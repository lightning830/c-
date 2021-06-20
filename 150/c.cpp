#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    vector<int> array;
    for(int i = 1; i <= n; i++){
        array.push_back(i);
    }
    vector<int> p;
    vector<int> q;
    rep(i, n){
        int a; cin >> a;
        p.push_back(a);
    }
    rep(i, n){
        int a; cin >> a;
        q.push_back(a);
    }
    int nn = 1;
    for(int i = 1; i <= n; i++) nn*=i;
    vector<vector<int>> tmp(n, vector<int>(nn));

    int num = 0;
    int pnum = 0, qnum = 0;
    do{
        num++;
        bool flagP = true, flagQ = true;
        rep(i, array.size()){
            if(array[i] != p[i]) flagP = false;
            if(array[i] != q[i]) flagQ = false;
        }
        if(flagP) pnum = num;
        if(flagQ) qnum = num;
        // rep(i, n){
        //     cout << array[i];
        // }
        // cout << endl;
    }while(next_permutation(array.begin(), array.end()));

    cout << abs(pnum-qnum) << endl;
}