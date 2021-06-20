#include<iostream>
#include<set>
#include<vector>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

int main(){
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<set<int>> is(26);
    rep(i, n) is[s[i]-'a'].insert(i); //ex) a: s[i]-'a'=0
    rep(qi, q){
        int ty;
        cin >> ty;
        if(ty == 1){
            int i; char c;//i番目をcにする
            cin >> i >> c;
            i--;
            is[s[i]-'a'].erase(i);
            s[i] = c;
            is[s[i]-'a'].insert(i);
        }else{
            int l, r;
            cin >> l >> r;
            l--;
            int ans = 0;
            rep(i, 26){
                auto it = is[i].lower_bound(l);//l以上で最小 setのイテレータ型
                if(it != is[i].end() && *it < r) ans++;//ない場合はendになる,ある場合はr未満かどうか
            }
            printf("%d\n", ans);
        }
    }
    return 0;
    // set<char> s;
    // s.insert('a');
    // s.insert('G');
    // s.insert('s');
    // s.insert('l');
    // s.insert('A');
    // s.insert('a');
    //AGals

}