#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    double n;
    cin >> n;
    rep(i, 40-(n-1)){
        double p = n / (40-i);
        cout << i+1 << "th " << p << endl;
    }

}