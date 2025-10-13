#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

stack<int> S;
vector<vector<int>> G, reverseG;
vector<bool> visited;

void dfs(int u) {
    if (visited[u]) return;
    visited[u] = true;
    for (int child : G[u]) {
        dfs(child);
    }
    S.push(u);
}

void dfs2(int u, ll& count) {
    if (visited[u]) return;
    visited[u] = true;
    count++;
    for (int child : reverseG[u]) {
        dfs2(child, count);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    G.resize(N + 1);
    reverseG.resize(N + 1);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        reverseG[b].push_back(a);
    }

    visited.assign(N + 1, false);
    for (int i = 1; i < N + 1; ++i) {
        dfs(i);
    }

    visited.assign(N + 1, false);
    ll res = 0;
    while (!S.empty()) {
        int u = S.top();
        S.pop();
        if (visited[u]) continue;
        ll c = 0;
        dfs2(u, c);
        res += (c * (c - 1)) / 2;
    }

    cout << res << endl;
    return 0;
}
