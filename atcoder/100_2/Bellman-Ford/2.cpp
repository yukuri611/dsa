#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

const ll INF = 1e14;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M, P;
    cin >> N >> M >> P;

    vector<tuple<int, int, ll>> Edges(M);
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c = -c + P;
        Edges[i] = {a, b, c};
    }

    // ベルマンフォード
    vector<ll> dist(N, INF);
    dist[0] = 0;
    rep(i, N - 1) {
        for (auto [a, b, c] : Edges) {
            if (dist[a] == INF) continue;
            dist[b] = min(dist[b], dist[a] + c);
        }
    }

    // ループの存在を調べる
    rep(i, N) {
        for (auto [a, b, c] : Edges) {
            if (dist[a] == INF) continue;
            if (dist[a] == -INF || dist[b] > dist[a] + c) {
                dist[b] = -INF;
            }
        }
    }

    if (dist[N - 1] == -INF) {
        cout << -1 << endl;
    } else {
        ll res = max(0LL, -dist[N - 1]);

        cout << res << endl;
    }

    return 0;
}
