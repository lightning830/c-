#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp> 
using namespace std;
using namespace boost::multiprecision;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

map<string, int> memo;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> sum(n,0);
    sum[0] = s[0]-'0';
    for(int i = 1; i < n; i++){
        sum[i] = sum[i-1] + (s[i] - '0'); 
    }
    ll ans = 0;
    // rep(i, n) cout << sum[i] << endl;
    for(int i = 0; i < n-4; i++){
        for(int j = i+3; j <= n-1; j++){
            int x;
            if(i-1 < 0){
                x = 0;
            }else x = sum[i-1];
            if((sum[j]-x) % 3 == 0){
                string t = s.substr(i, j-i+1);
                // cout << t << endl;
                cpp_int a = atoi(t.c_str());
                // cout << a << endl;
                if(a%673==0) ans++;
            }

        }
    }
    cout << ans << endl;
}