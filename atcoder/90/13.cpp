#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

struct Edge {
    int v;
    ll cost;
};

vector<vector<Edge>> G;
int N, M;

vector<ll> dijkstra(int s) {
    vector<ll> dist(N, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        auto [c, u] = pq.top();
        pq.pop();
        for (auto [v, c] : G[u]) {
            ll new_cost = dist[u] + c;
            if (dist[v] > new_cost) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }
    return dist;
}

int main() {
    cin >> N >> M;
    G.resize(N);
    rep(i, M) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    auto dist1 = dijkstra(0);      // dist from 0
    auto dist2 = dijkstra(N - 1);  // dist to N
    rep(k, N) { cout << dist1[k] + dist2[k] << endl; }
    return 0;
}
