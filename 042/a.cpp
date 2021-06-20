#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 5 && b == 5 && c == 7){
        cout << "YES" << endl;
    }else if(a == 7 && b == 5 && c == 5){
        cout << "YES" << endl;
    }else if(a == 5 && b == 7 && c == 5){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}