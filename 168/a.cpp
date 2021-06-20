#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    int n; cin >> n;
    n = n % 10;
    if(n == 2 || n == 4 || n == 5 || n == 7 || n == 9){
        cout << "hon" << endl;
    }else if(n == 0 || n == 1 || n == 6 || n == 8){
        cout << "pon" << endl;
    }else{
        cout << "bon" << endl;
    }

    return 0;
}