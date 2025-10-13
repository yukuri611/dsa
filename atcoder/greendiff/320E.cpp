#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    for (int i = 1; i < N + 1; ++i) pq2.push(i);
    vector<ll> res(N + 1, 0);
    rep(i, M) {
        int t, w, s;
        cin >> t >> w >> s;
        while (!pq1.empty() && pq1.top().first <= t) {
            auto u = pq1.top().second;
            pq1.pop();
            pq2.push(u);
        }
        if (pq2.empty()) continue;
        int u = pq2.top();
        pq2.pop();
        res[u] += w;
        pq1.push({t + s, u});
    }

    for (int i = 1; i < N + 1; ++i) cout << res[i] << endl;
    return 0;
}
