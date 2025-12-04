#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V);
    vector<int> degree(V, 0);
    rep(i, E) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
        degree[t]++;
    }

    queue<int> q;
    rep(i, V) if (degree[i] == 0) q.push(i);

    vector<int> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (auto v : G[u]) {
            degree[v]--;
            if (degree[v] == 0) q.push(v);
        }
    }

    for (auto a : ans) cout << a << endl;
    return 0;
}
