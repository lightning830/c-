#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

void f(vector<int> x){
    x[1] = 10;
    for(auto& xx: x) cout << xx << endl;
    
}

int main() {
    vector<int> a{1, 2, 3};
    vector<int> b = a;
    b.back() = 20;
    for(auto& x: a) cout << x << endl;
    // f(a);
    for(auto& x: b) cout << x << endl;
    cout << endl;
    cout << b.back() << endl;
    return 0;
}