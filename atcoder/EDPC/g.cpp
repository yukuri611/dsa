#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
template <typename T>
bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

vector<int> length;
vector<vector<int>> G;

int main() {
    int N, M;
    cin >> N >> M;
    G.resize(N);
    vector<int> degree(N);
    rep(i, M) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
        degree[y]++;
    }

    queue<int> q;
    rep(i, N) if (degree[i] == 0) q.push(i);

    vector<int> dp(N);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v : G[u]) {
            chmax(dp[v], dp[u] + 1);
            degree[v]--;
            if (degree[v] == 0) q.push(v);
        }
    }
    int ans = 0;
    rep(i, N) chmax(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
