#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    double a, b, x;
    cin >> a >> b >> x;
    // cout << a*b - x/a << endl;
    double y = 2.0*b - 2.0*x/(a*a);
    if(y > b){
        y = (x/a)*(2.0/b);
        printf("%.10lf\n", 90.0-atan(y/b)*(180/M_PI));
    }else{
        printf("%.10lf\n", atan(y/a)*(180/M_PI));
    }
    // cout << y << endl;
    // printf("%.10lf\n", atan(y/a)*(180/M_PI));
    // cout << atan(y/a)*(180/M_PI) << endl;
}