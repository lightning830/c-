// 幅優先探索
// メモ用
//スタート地点(s)からの距離をdistに入れる。この個数がスタート(s固定)からゴールのパターン


int main() {
    lint N, M;
    cin >> N >> M;
    VVl to(N);
    REP(i, M) {
        lint A, B;
        cin >> A >> B; A--; B--;
        to[A].push_back(B);
    }

    lint ans = 0;
    for (int i = 0; i < N; i++) {//各町スタート
        lint s = i;

        Vl dist(N, INF);
        queue<lint> que;
        que.push(s);
        dist[s] = 0;//dist[x]:sからxまでの距離
        while (!que.empty()) {
            lint curr = que.front(); que.pop();
            for (lint nxt : to[curr]) {
                if (dist[nxt] > dist[curr] + 1) {//次が1個差はもう書いてあるから無視してok(処理してもいいが、どうせ+1を代入するから変わらないけど)
                    dist[nxt] = dist[curr] + 1;//+1の距離を代入する
                    que.push(nxt);
                }
            }
        }

        for (int j = 0; j < N; j++) {
            if (dist[j] != INF) ans++;//町の距離が書いてあるものを加算してく
        }
    }
    cout << ans << endk;
}