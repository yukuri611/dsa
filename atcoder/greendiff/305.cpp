#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> G(N + 1);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> P(K), H(K);
    rep(i, K) cin >> P[i] >> H[i];

    priority_queue<pair<int, int>> pq;
    rep(i, K) { pq.push({H[i], P[i]}); }

    vector<int> maxHealth(N + 1, -1);
    while (!pq.empty()) {
        auto [h, p] = pq.top();
        pq.pop();
        if (maxHealth[p] != -1) continue;
        maxHealth[p] = h;
        if (h == 0) continue;
        for (int nextNode : G[p]) {
            if (maxHealth[nextNode] != -1) continue;
            pq.push({h - 1, nextNode});
        }
    }

    vector<int> res_list;
    for (int i = 1; i < N + 1; ++i) {
        if (maxHealth[i] > -1) res_list.push_back(i);
    }

    cout << res_list.size() << endl;
    for (int res : res_list) cout << res << " ";
    cout << endl;
    return 0;
}
