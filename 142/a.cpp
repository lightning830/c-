#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n; cin >> n;
    double a;
    if(n % 2 == 0){
        a = n/2;
    }else{
        a = n/2 + 1;
    }
    printf("%.10f", a/n);

    return 0;
}