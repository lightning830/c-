#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main(){
    char s[] = {'R', 'J', 'B', '\0'};
    rep(i, strlen(s)){
        cout << bitset<8>(s[i]) << endl;
    }
    cout << "R^G^B " << bitset<8>(s[0]^s[1]^s[2]) << endl;
    cout << "R^R^B " << bitset<8>(s[0]^s[0]^s[2]) << endl;
    cout << "R^R^R " << bitset<8>(s[0]^s[0]^s[0]) << endl;
    cout << "R&G&B " << bitset<8>(s[0]&s[1]&s[2]) << endl;
    cout << "R&R&B " << bitset<8>(s[0]&s[0]&s[2]) << endl;
    cout << "R&R&R " << bitset<8>(s[0]&s[0]&s[0]) << endl;
    
}
