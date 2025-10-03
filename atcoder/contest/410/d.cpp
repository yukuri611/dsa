#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

struct Edge {
    int to, w;
};

int main() {
    int N, M;
    cin >> N >> M;
    int W = (1 << 10);

    vector<vector<Edge>> G(N);
    rep(i, M) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        G[a].push_back({b, w});
    }

    vector<bool> visited(N * W, false);
    queue<int> q;
    visited[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int u = x / W;
        int s = x % W;
        for (auto [v, w] : G[u]) {
            int ns = s ^ w;
            int nx = v * W + ns;
            if (visited[nx]) continue;
            q.push(nx);
            visited[nx] = true;
        }
    }
    rep(s, W) {
        int x = (N - 1) * W + s;
        if (visited[x]) {
            cout << s << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
