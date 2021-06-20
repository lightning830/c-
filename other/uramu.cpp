

#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {

    ll range = 5;
    int x = 0;
    int y = 0;
    ll loop = 0;
    ll shift = 0;
    int a[range][range];
    for (ll i = 1; i <= range * range; i++) {
        std::cout<<x<<" "<<y<<" "<<i<<std::endl;
        //x = 上に y = 左に
        a[range/2-x][range/2-y] = i;
        if (i == (loop * 2 + 1) * (loop * 2 + 1)) {
            loop++;
            shift = 0;
            x++;
        }
        else {
            shift++;
            if (shift >= loop * 6) { x++; }//上へ
            else if (shift >= loop * 4) { y--; }//右へ
            else if (shift >= loop * 2) { x--; }//下へ
            else { y++; }//左へ
        }
    }
    rep(i, range){
        rep(j, range){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}