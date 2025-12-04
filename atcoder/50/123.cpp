#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

struct Edge {
    int to;
    ll cap;
    int rev;
};

class Dinic {
   public:
    int n;
    vector<vector<Edge>> G;
    vector<int> level;
    vector<int> iter;

    Dinic(int n) : n(n), G(n), level(n), iter(n) {}

    void add_edge(int from, int to, ll cap) {
        G[from].push_back({to, cap, (int)G[to].size()});
        G[to].push_back({from, 0, (int)G[from].size() - 1});
    }

    // BFS
    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto& e : G[v]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    // DFS
    ll dfs(int v, int t, ll f) {
        if (v == t) return f;

        for (int& i = iter[v]; i < G[v].size();
             ++i) {  // iter[v]より前の辺は探索済み
            Edge& e = G[v][i];
            if (e.cap > 0 &&
                level[v] < level[e.to]) {  // レベルが増加する方向にのみ
                ll d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    ll max_flow(int s, int t) {
        ll flow = 0;
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;

            fill(iter.begin(), iter.end(), 0);
            ll f;
            while ((f = dfs(s, t, 1e18)) > 0) {
                flow += f;
            }
        }
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Dinic dinic(V);
    rep(i, E) {
        int u, v, c;
        cin >> u >> v >> c;
        dinic.add_edge(u, v, c);
    }

    cout << dinic.max_flow(0, V - 1) << endl;
    return 0;
}
