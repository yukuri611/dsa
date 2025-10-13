#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
<<<<<<< HEAD
=======
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

>>>>>>> 7f66d8cb80dfaafc27b89d5afbb04532fb31df9b
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> G(N + 1);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
<<<<<<< HEAD
    vector<int> P(K), H(K);
    rep(i, K) cin >> P[i] >> H[i];
=======
>>>>>>> 7f66d8cb80dfaafc27b89d5afbb04532fb31df9b

    vector<int> health(N + 1, -1);
    priority_queue<pair<int, int>> pq;
<<<<<<< HEAD
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
=======
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
>>>>>>> 7f66d8cb80dfaafc27b89d5afbb04532fb31df9b
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
