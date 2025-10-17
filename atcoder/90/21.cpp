#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

vector<vector<int>> G;
vector<vector<int>> H;

void dfs1(int curr, vector<int> &order, vector<bool> &visited) {
    visited[curr] = true;
    for (int nextnode : G[curr]) {
        if (visited[nextnode]) continue;
        dfs1(nextnode, order, visited);
    }
    order.push_back(curr);
}

ll dfs2(int curr, vector<bool> &visited) {
    visited[curr] = true;
    ll res = 1;
    for (int nextnode : H[curr]) {
        if (!visited[nextnode]) res += dfs2(nextnode, visited);
    }
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;
    G.resize(N + 1);
    H.resize(N + 1);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        H[b].push_back(a);
    }

    vector<int> order;
    vector<bool> visited(N + 1, false);
    for (int i = 1; i < N + 1; ++i) {
        if (!visited[i]) dfs1(i, order, visited);
    }

    visited.assign(N + 1, false);
    reverse(order.begin(), order.end());

    ll res = 0;
    rep(i, N) {
        if (!visited[order[i]]) {
            ll c = dfs2(order[i], visited);
            res += (c * (c - 1)) / 2;
        }
    }
    cout << res << endl;
    return 0;
}
