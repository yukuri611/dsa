#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

vector<vector<int>> G;
vector<int> dist;
int N;

void dfs(int u, int prev, int d) {
    for (int v : G[u]) {
        if (v == prev) continue;
        dfs(v, u, d + 1);
    }
    dist[u] = d;
}

int main() {
    cin >> N;
    G.resize(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dist.resize(N, 0);
    dfs(0, -1, 1);
    int u = 0;
    rep(i, N) {
        if (dist[i] < dist[u]) u = i;
    }

    fill(dist.begin(), dist.end(), 0);
    dfs(u, -1, 1);
    int res = dist[0];
    rep(i, N) res = max(res, dist[i]);

    cout << res << endl;
    return 0;
}
