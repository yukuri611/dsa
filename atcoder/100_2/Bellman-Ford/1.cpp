#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    vector<tuple<int, int, ll>> Edges(M);
    rep(i, M) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        c = -c;
        Edges.push_back({a, b, c});
    }

    vector<ll> dist(N, INF);
    dist[0] = 0;
    rep(iter, N - 1) {
        for (auto [a, b, c] : Edges) {
            dist[b] = min(dist[b], dist[a] + c);
        }
    }

    rep(iter, N) {
        for (auto [a, b, c] : Edges) {
            if (dist[a] == INF) continue;
            if (dist[a] == -INF || dist[b] > dist[a] + c) {
                dist[b] = -INF;
            }
        }
    }

    if (dist[N - 1] == -INF) {
        cout << "inf" << endl;
        return 0;
    }

    cout << -dist[N - 1] << endl;
    return 0;
}
