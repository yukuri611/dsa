#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, ll>>> G(N);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c = -c;
        G[a].push_back({b, c});
    }

    // 最短経路を求める（ベルマンフォード）
    vector<ll> dist(N, LLONG_MAX);
    dist[0] = 0;
    rep(i, N - 1) {
        rep(u, N) {
            if (dist[u] == LLONG_MAX) continue;
            for (auto [v, c] : G[u]) {
                dist[v] = min(dist[v], dist[u] + c);
            }
        }
    }

    // 負閉路の存在をチェック
    vector<ll> dist_copy = dist;
    rep(i, N) {
        rep(u, N) {
            if (dist[u] == LLONG_MAX) continue;
            for (auto [v, c] : G[u]) {
                dist_copy[v] = min(dist_copy[v], dist_copy[u] + c);
            }
        }
    }

    if (dist[N - 1] != dist_copy[N - 1]) {
        cout << "inf" << endl;
        return 0;
    }

    cout << -dist[N - 1] << endl;
    return 0;
}
