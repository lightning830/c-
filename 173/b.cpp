#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n; cin >> n;
    string s[n];
    int a[4];
    rep(i, 4) a[i] = 0;
    rep(i, n){
        cin >> s[i];
        if(s[i] == "AC") a[0]++;
        if(s[i] == "WA") a[1]++;
        if(s[i] == "TLE") a[2]++;
        if(s[i] == "RE") a[3]++;
    }

    cout << "AC x " << a[0] << endl;
    cout << "WA x " << a[1] << endl;
    cout << "TLE x " << a[2] << endl;
    cout << "RE x " << a[3] << endl;
    

    return 0;
}