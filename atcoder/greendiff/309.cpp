#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N + 1);
    for (int i = 2; i < N + 1; ++i) {
        int p;
        cin >> p;
        G[p].push_back(i);
    }

    vector<int> remain(N + 1, -1);
    rep(i, M) {
        int x, y;
        cin >> x >> y;
        remain[x] = max(remain[x], y);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            remain[v] = max(remain[v], remain[u] - 1);
            q.push(v);
        }
    }

    int res = 0;
    for (int i = 1; i < N + 1; ++i) {
        if (remain[i] >= 0) res++;
    }

    cout << res << endl;
    return 0;
}
