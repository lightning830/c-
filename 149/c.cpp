#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;

bool is_prime(int n){
    if(n == 1) return false;
    for(int k = 2; k < int(sqrt(n))+1; k++){
        if(n % k == 0) return false;
    }
    return true;
}

int main(){
    int x;
    cin >> x;
    while(1){
        bool check = is_prime(x);
        if(check) break;
        x++;
    }
    cout << x << endl;
}