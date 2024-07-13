#include <iostream>
#include <vector>
using namespace std;

// 連結成分でデッドロックが発生していない ⇔ 連結成分が直線型のグラフ (パス) になっている
// 連結成分でデッドロックが発生している ⇔ 連結成分が円形のグラフ (ループ) になっている


int main() {
  int N, M;
  bool ans = false;
  cin >> N >> M;
  vector<int> S(M + 1), T(M + 1), room(N + 1);
  vector<bool> visit(M + 1);
  for (int i = 1; i <= M; i++) {
    cin >> S[i] >> T[i];
    room[S[i]] = i;
  }
  for (int i = 1; i <= M; i++) {
    if (room[T[i]] == i) continue;

    int P = i;
    while (true) {
      if (visit[P] == true) {
        break;
      }
      visit[P] = true;
      if (room[T[P]] == 0) {
        break;
      }
      P = room[T[P]];
      if (P == i) {
        ans = true;
        break;
      }
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
}