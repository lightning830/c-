#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int n, k;
    cin >> n >> k;
    double p = 0;
    for(int i = 1; i <= n; i++){
        double p1 = 1;
        int point = i;
        while(point < k){
            // cout << i << endl;
            point *= 2;
            // cout << point << endl;
            p1 *= 0.5;
        }
        p+=p1;
    }
    printf("%.12f\n", p/n);
    // cout << p/n << endl;

    return 0;
}