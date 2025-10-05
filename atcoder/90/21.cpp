#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int N, M;
vector<bool> visited;
vector<vector<int>> G;
vector<vector<int>> Ginv;
vector<int> I;
ll cnt;
void dfs(int a) {
    visited[a] = true;
    for (int child : G[a]) {
        if (!visited[child]) dfs(child);
    }
    I.push_back(a);
}

void dfs2(int a) {
    visited[a] = true;
    cnt++;
    for (int child : Ginv[a]) {
        if (!visited[child]) dfs2(child);
    }
}

int main() {
    cin >> N >> M;
    G.resize(N);
    Ginv.resize(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        Ginv[b].push_back(a);
    }

    visited.assign(N, false);

    // Kosaraju's Algorithm
    // step1. first DFS
    rep(i, N) {
        if (!visited[i]) dfs(i);
    }
    reverse(I.begin(), I.end());

    // step2. second dfs
    visited.assign(N, false);
    ll ans = 0;
    rep(i, N) {
        if (visited[I[i]]) continue;
        cnt = 0;
        dfs2(I[i]);
        ans += (cnt * (cnt - 1)) / 2;
    }

    cout << ans << endl;
    return 0;
}
