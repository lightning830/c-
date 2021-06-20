#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;


int main(){
    int n;
    printf("Numbers = ");
    cin >> n;

    char ch = 'a';

    rep(i, 1<<n){//全探索
        printf("%d)", i);
        rep(j, n){
            if(i>>j & 1){//jビット目が1なら
                printf("%c ", ch+j);
            }
        }
        printf("\n");
    }
}