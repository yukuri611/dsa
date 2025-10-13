// topological sort
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

struct Edge {
    ll v, dx, dy;
};

int N, M;
vector<vector<Edge>> G;

void topologicalSort() {}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    G.resize(N + 1);
    rep(i, M) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        G[a].push_back({b, x, y});
        G[b].push_back({a, -x, -y});
    }

    vector<pair<ll, ll>> pos(N + 1);
    vector<bool> visited(N + 1, false);
    pos[1] = {0, 0};
    visited[1] = true;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto [v, dx, dy] : G[u]) {
            if (visited[v]) continue;
            pos[v] = {pos[u].first + dx, pos[u].second + dy};
            visited[v] = true;
            q.push(v);
        }
    }

    for (int i = 1; i < N + 1; ++i) {
        if (visited[i])
            cout << pos[i].first << " " << pos[i].second << endl;
        else
            cout << "undecidable" << endl;
    }

    return 0;
}
