#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int x; cin >> x;
    int happy = 0;

    happy += (x/500)*1000;
    x -= (x/500)*500;
    happy += (x/5)*5;

    cout << happy << endl;

}