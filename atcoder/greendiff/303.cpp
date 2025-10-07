#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int N;
vector<vector<int>> G;
vector<bool> visited;
vector<int> res_list;

int dfs(int curr, int prev) {
    for (int child : G[curr]) {
        if (child == prev)
            continue;
        else {
            return dfs(child, curr);
        }
    }
    return curr;
}

void dfs2(int curr, int d) {
    if (d % 3 == 0) {
        res_list.push_back(G[curr].size());
    }
    for (int child : G[curr]) {
        if (visited[child]) continue;
        visited[child] = true;
        dfs2(child, d + 1);
    }
}

int main() {
    cin >> N;
    G.resize(N + 1);
    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int leaf = dfs(1, 0);
    int pivot = G[leaf][0];
    visited.assign(N + 1, false);
    visited[pivot] = true;

    dfs2(pivot, 0);

    sort(res_list.begin(), res_list.end());
    for (int res : res_list) cout << res << " ";
    cout << endl;
    return 0;
}
