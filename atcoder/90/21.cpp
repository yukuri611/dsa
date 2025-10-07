#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int N, M;
ll cnt;
vector<vector<int>> G;
vector<vector<int>> H;

vector<int> mark;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : G[u]) {
        if (!visited[v]) dfs(v);
    }
    mark.push_back(u);
}

void dfs2(int u) {
    visited[u] = true;
    cnt++;
    for (int v : H[u]) {
        if (!visited[v]) dfs2(v);
    }
}

int main() {
    cin >> N >> M;
    G.resize(N + 1);
    H.resize(N + 1);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        H[b].push_back(a);
    }

    visited.resize(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        if (visited[i]) continue;
        dfs(i);
    }

    ll res = 0;
    visited.assign(N + 1, false);
    for (int i = N - 1; i >= 0; --i) {
        if (!visited[mark[i]]) {
            cnt = 0;
            dfs2(mark[i]);
            res += (cnt * (cnt - 1)) / 2;
        }
    }

    cout << res << endl;
    return 0;
}
