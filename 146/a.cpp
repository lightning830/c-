#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    string s;
    cin >> s;
    if(s == "SUN") cout << 7 << endl;
    if(s == "MON") cout << 6 << endl;
    if(s == "TUE") cout << 5 << endl;
    if(s == "WED") cout << 4 << endl;
    if(s == "THU") cout << 3 << endl;
    if(s == "FRI") cout << 2 << endl;
    if(s == "SAT") cout << 1 << endl;
}