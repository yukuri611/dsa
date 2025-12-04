#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

vector<pair<ll, ll>> dp;  // black, white
vector<vector<int>> Tree;
int mod = 1e9 + 7;
void dfs(int cur, int parent) {
    dp[cur] = {1, 1};
    for (auto nxt : Tree[cur]) {
        if (nxt == parent) continue;
        dfs(nxt, cur);
        dp[cur].first *= dp[nxt].second;
        dp[cur].first %= mod;
        dp[cur].second *= dp[nxt].first + dp[nxt].second;
        dp[cur].second %= mod;
    }
}

int main() {
    int N;
    cin >> N;
    Tree.resize(N);
    rep(i, N - 1) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        Tree[x].push_back(y);
        Tree[y].push_back(x);
    }

    dp.resize(N);
    dfs(0, -1);
    cout << (dp[0].first + dp[0].second) % mod << endl;
}
