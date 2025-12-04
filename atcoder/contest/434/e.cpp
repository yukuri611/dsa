#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N;
    cin >> N;
    vector<int> X(N), R(N), Grid;
    rep(i, N) {
        int x, r;
        cin >> x >> r;
        X[i] = x;
        R[i] = r;
        Grid.push_back(x + r);
        Grid.push_back(x - r);
    }

    // 座圧
    sort(Grid.begin(), Grid.end());
    Grid.erase(unique(Grid.begin(), Grid.end()), Grid.end());
    int M = Grid.size();
    vector<vector<int>> G(M);
    rep(i, N) {
        int x = X[i], r = R[i];
        int node1 = lower_bound(Grid.begin(), Grid.end(), x - r) - Grid.begin();
        int node2 = lower_bound(Grid.begin(), Grid.end(), x + r) - Grid.begin();
        G[node1].push_back(node2);
        G[node2].push_back(node1);
    }

    // 連結成分ごとにカウント。木構造ならノード数-1,
    // それ以外はノード数をansに加える
    dsu uf(M);
    vector<int> edge_count(M);
    rep(u, M) {
        for (auto v : G[u]) {
            uf.merge(u, v);
        }
    }
    rep(i, N) {
        int x = X[i], r = R[i];
        int node = lower_bound(Grid.begin(), Grid.end(), x - r) - Grid.begin();
        edge_count[uf.leader(node)]++;
    }

    int ans = 0;
    for (auto& group : uf.groups()) {
        int root = uf.leader(group[0]);
        int sz = group.size();
        if (edge_count[root] >= sz)
            ans += sz;
        else
            ans += sz - 1;
    }

    cout << ans << endl;
    return 0;
}
