#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M; cin >> N >> M;
    vector<int> P(N + 1, 0);
    for (int i = 2; i < N + 1; ++i) cin >> P[i];
    vector<vector<int>> G(N + 1);
    for(int i = 2; i <= N; ++i) {
        G[P[i]].push_back(i);
    } 
    vector<int> X(M), Y(M);
    rep(i, M) cin >> X[i] >> Y[i];

    priority_queue<pair<int, int>> pq;
    rep(i, M) {
        pq.push({Y[i], X[i]});
    }
    vector<int> remain(N + 1, -1);
    while(!pq.empty()) {
        auto [y, x] = pq.top();
        pq.pop();
        if (remain[x] > y) continue;
        remain[x] = y;
        if (y == 0) continue;
        for (int child: G[x]) {
            if (remain[child] > y - 1) continue;
            remain[child] = y - 1;
            pq.push({y - 1, child});
        }
    }

    int res = 0;
    for (int i = 1; i < N + 1; ++i) {
        if (remain[i] != -1) res++;
    }
    cout << res << endl;
    return 0;
}
