// 問題を二つに分割する。
// 1.
// 拾うポーションを決める。敵の番号と一致するポーションの中で一番最後に拾ったものを使用する。
// 2.
// Kの最小値を計算。拾うポーションが決まっていれば、単純に現在のポーション数をカウントする変数を変化させていけばいいだけ。

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> T(N), X(N);
    rep(i, N) cin >> T[i] >> X[i];

    map<int, vector<int>> Map;
    vector<int> used(N, 0);
    rep(i, N) {
        int t = T[i], x = X[i];
        if (t == 1) {
            Map[x].push_back(i);
        } else {
            if (Map[x].size() == 0) {
                cout << -1 << endl;
                return 0;
            }
            used[Map[x].back()] = 1;
            Map[x].pop_back();
        }
    }

    int K = 0;
    int portion_cnt = 0;
    rep(i, N) {
        if (used[i])
            portion_cnt++;
        else if (T[i] == 2)
            portion_cnt--;
        K = max(K, portion_cnt);
    }

    cout << K << endl;
    rep(i, N) {
        if (T[i] == 2) continue;
        cout << used[i] << " ";
    }

    return 0;
}
