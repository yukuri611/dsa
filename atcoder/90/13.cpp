#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

struct Edge {
    int v, cost;
};

vector<vector<Edge>> G;
int N, M;

void dijkstra(int start, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, start});
    while (!pq.empty()) {
        auto [currC, u] = pq.top();
        pq.pop();
        if (currC > dist[u]) continue;
        dist[u] = currC;
        for (auto [v, c] : G[u]) {
            if (dist[v] != INT_MAX) continue;
            int newCost = currC + c;
            pq.push({newCost, v});
        }
    }
}

int main() {
    cin >> N >> M;
    G.resize(N + 1);
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    vector<int> dist1(N + 1, INT_MAX), distN(N + 1, INT_MAX);
    dijkstra(1, dist1);
    dijkstra(N, distN);

    for (int k = 1; k <= N; ++k) {
        cout << dist1[k] + distN[k] << endl;
    }
    return 0;
}
