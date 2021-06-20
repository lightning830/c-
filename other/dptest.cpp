#include<cstdio>
#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

//Nは桁数が大きい場合があるので文字列として受け取る
string N;
vector<int> n;  //Nの各桁の数字を格納するベクター
int dp[100][2][2];

int main(){
  cin>>N;

  //ベクターnを構成
  for(auto a : N){
    n.push_back(a-'0');
  }
  int l = N.size();  //nの長さ
//   cout << l << endl;

  dp[0][0][0] = 1;  //初期条件。他は0で初期化されている
  for(int i = 0; i < l; i++){
    for(int smaller = 0; smaller < 2; smaller++){
      for(int j = 0; j < 2; j++){
        for(int x = 0; x <= (smaller ? 9 : n[i]); x++){
          dp[i + 1][smaller || x < n[i]][j || x == 3] += dp[i][smaller][j];          
        }
      }
    }
  }

  cout << dp[l][0][1] + dp[l][1][1] << endl;
    // rep(i, l+1)rep(j, 2)rep(k, 2){
    //     cout << dp[i][j][k] << " i=" << i << "j=" << j << "k=" << k << endl;
    // }
  return 0;
}