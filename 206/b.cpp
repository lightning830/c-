#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;


int main() {
    int N;
    cin >> N;

    int start = sqrt(2*N);
    // cout << start << endl;

    while(1){
        ll x = start*(start+1);
        // cout << x << endl;
        if(x >= 2*N){
            cout << start << endl;
            break;
        }else{
            start++;
        }
    }

    return 0;
}