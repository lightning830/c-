#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n;
    string s;
    cin >> n >> s;
    rep(i, s.size()){
        if(s[i]-'0'+n > 42){
            s[i] = s[i]-(26-n);
        }else s[i] = s[i]+n;
    }
    cout << s << endl;
    // cout << 'Z'-'0' << endl; 
}