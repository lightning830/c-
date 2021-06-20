#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

ll gcd(ll a, ll b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

ll lcm(ll a, ll b)
{
   return a * b / gcd(a, b);
}

int main() {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll b1 = b;
    b1 -= b/c;
    b1 -= b/d;

    ll l = lcm(c, d);
    b1 += b/l;

    ll a1 = a-1;
    a1 -= (a-1)/c;
    a1 -= (a-1)/d;
    a1 += (a-1)/l;

    // cout << b1 << " " << a1 << endl;
    cout << b1-a1 << endl;

    return 0;
}