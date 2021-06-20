#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    double a, b, h, m;
    cin >> a >> b >> h >> m;
    double hkaku = (30*h + m/2);
    double mkaku = 6*m;
    double theta = abs(hkaku - mkaku);
    printf("%.12f", sqrt(a*a + b*b - 2*a*b*cos(theta*M_PI/180)));

    return 0;
}