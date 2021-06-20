#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;
const int INF = 1001001001;

int main() {
    int x;
    cin >> x;

    double price = 1.08 * x;
    // cout << price << endl;

    if((int)price < 206){
        cout << "Yay!" << endl;
    }else if((int)price == 206){
        cout << "so-so" << endl;
    }else{
        cout << ":(" << endl;
    }

    return 0;
}