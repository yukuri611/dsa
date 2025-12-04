#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    vector<int> degree(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        degree[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i, N) if (degree[i] == 0) pq.push(i);
    vector<int> ans;
    while (!pq.empty()) {
        auto u = pq.top();
        pq.pop();
        ans.push_back(u + 1);  // 1-indexed
        for (auto v : G[u]) {
            degree[v]--;
            if (degree[v] == 0) pq.push(v);
        }
    }

    if (ans.size() < N)
        cout << -1 << endl;
    else {
        for (auto a : ans) cout << a << " ";
        cout << endl;
    }
    return 0;
}
