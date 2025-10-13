#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int N;
vector<char> C;
vector<vector<int>> Tree;
vector<vector<ll>> dp;
ll mod = 1e9 + 7;

void dfs(int cur, int pre) {
    for (int child : Tree[cur]) {
        if (child == pre) continue;
        dfs(child, cur);
    }
    if (C[cur] == 'a') {
        dp[cur][1] = 0;
        int c = 0;
        for (int child : Tree[cur]) {
            if (child == pre) continue;
            dp[cur][0] *= dp[child][0] + dp[child][2];
            dp[cur][0] %= mod;
            dp[cur][2] *= dp[child][0] + dp[child][1] + 2 * dp[child][2];
            dp[cur][2] %= mod;
            c++;
        }
        dp[cur][2] = dp[cur][2] - dp[cur][0] + mod;
        dp[cur][2] %= mod;
        if (c == 0) dp[cur][2] = 0;
    } else {
        dp[cur][0] = 0;
        int c = 0;
        for (int child : Tree[cur]) {
            if (child == pre) continue;
            dp[cur][1] *= dp[child][1] + dp[child][2];
            dp[cur][1] %= mod;
            dp[cur][2] *= dp[child][0] + dp[child][1] + 2 * dp[child][2];
            dp[cur][2] %= mod;
            c++;
        }
        dp[cur][2] = dp[cur][2] - dp[cur][1] + mod;
        dp[cur][2] %= mod;
        if (c == 0) dp[cur][2] = 0;
    }
}

int main() {
    cin >> N;
    C.resize(N);
    rep(i, N) cin >> C[i];
    Tree.resize(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    dp.resize(N, vector<ll>(3, 1));
    dfs(0, -1);

    cout << dp[0][2] << endl;
    return 0;
}
