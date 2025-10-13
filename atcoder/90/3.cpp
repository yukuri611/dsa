#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

vector<vector<int>> G;

pair<int, int> dfs(int cur, int prev) {
    int dist = 0;
    int node = 0;
    for (int child : G[cur]) {
        if (child == prev) continue;
        auto [newDist, newNode] = dfs(child, cur);
        if (dist < newDist) {
            dist = newDist;
            node = newNode;
        }
    }
    if (node == 0) node = cur;
    return {dist + 1, node};
}

int main() {
    int N;
    cin >> N;
    G.resize(N + 1);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int u = dfs(1, 0).second;
    int res = dfs(u, 0).first;
    cout << res << endl;
    return 0;
}
