#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<ll>> A(N, vector<ll>(N));
    rep(i, N) { rep(j, N) cin >> A[i][j]; }

    rep(i, N) {
        rep(j, N) rep(k, N) if (A[i][k] + A[k][j] < A[i][j]) {
            cout << -1 << endl;
            return 0;
        }
    }

    vector<tuple<ll, int, int>> edges;
    rep(i, N) {
        for (int j = i + 1; j < N; ++j) {
            edges.push_back({A[i][j], i, j});
        }
    }
    sort(edges.begin(), edges.end(),
         [](tuple<ll, int, int> a, tuple<ll, int, int> b) {
             return get<0>(a) < get<0>(b);
         });

    vector<vector<ll>> dist(N, vector<ll>(N, LLONG_MAX));
    ll res = 0;
    for (auto [d, u, v] : edges) {
        if (dist[u][v] > d) {
            dist[u][v] = d;
            dist[v][u] = d;
            res += d;

            rep(i, N) {
                rep(j, N) {
                    if (dist[i][u] != LLONG_MAX && dist[j][u] != LLONG_MAX)
                        dist[i][j] =
                            min(dist[i][j], dist[i][u] + dist[v][j] + d);
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
