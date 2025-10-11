#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll N, A, B, C;
vector<vector<ll>> D;
vector<ll> T;

void dijkstra1() {
    T[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        auto [t, u] = pq.top();
        pq.pop();
        if (T[u] < t) continue;
        for (int v = 1; v < N + 1; ++v) {
            if (u == v) continue;
            ll newTime = t + D[u][v] * A;
            if (T[v] > newTime) {
                T[v] = newTime;
                pq.push({newTime, v});
            }
        }
    }
}

void dijkstra2() {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        pq;
    for (int i = 1; i < N + 1; ++i) pq.push({T[i], i});
    while (!pq.empty()) {
        auto [t, u] = pq.top();
        pq.pop();
        if (T[u] < t) continue;
        for (int v = 1; v < N + 1; ++v) {
            if (u == v) continue;
            ll newTime = t + D[u][v] * B + C;
            if (T[v] > newTime) {
                T[v] = newTime;
                pq.push({T[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> A >> B >> C;
    D.resize(N + 1, vector<ll>(N + 1));
    for (int i = 1; i < N + 1; ++i) {
        for (int j = 1; j < N + 1; ++j) {
            cin >> D[i][j];
        }
    }

    T.resize(N + 1, LLONG_MAX);
    dijkstra1();
    dijkstra2();

    cout << T[N] << endl;
    return 0;
}
