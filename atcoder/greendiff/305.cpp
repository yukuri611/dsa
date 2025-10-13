#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> G(N + 1);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> health(N + 1, -1);
    priority_queue<pair<int, int>> pq;
    rep(i, K) {
        int p, h;
        cin >> p >> h;
        health[p] = h;
        pq.push({h, p});
    }

    while (!pq.empty()) {
        auto [h, u] = pq.top();
        pq.pop();
        for (int v : G[u]) {
            if (health[v] < h - 1) {
                health[v] = h - 1;
                pq.push({h - 1, v});
            }
        }
    }

    vector<int> res_list;
    for (int i = 1; i < N + 1; ++i) {
        if (health[i] > -1) res_list.push_back(i);
    }

    cout << res_list.size() << endl;
    for (int res : res_list) cout << res << " ";
    cout << endl;
    return 0;
}
