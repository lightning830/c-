#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a(20, 10);
    int n = 10;
    int res = 0;
    while(n > 0){
        res += a[n];
        n -= n&(-n);
    }
    cout << res << endl;
    cout << n << endl;
}