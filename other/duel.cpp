#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int, int>;
using ll = long long;

int main() {
    ofstream log;
    log.open("log.csv", ios::trunc);//ファイル出力
    rep(i, 30){
        double x = 1.0 - ((double)(40-i)*(39-i)*(38-i)*(37-i)*(36-i))/(40*39*38*37*36);
        cout << i << "枚加えるとシールドにそのカードが出現する確率は"
            << x << endl;
        log << i << ',' << x << endl;//書き込み
        if(x >= 1.0) break;
    }

}