#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll mod = 1e9 + 7;

vector<vector<int>> G;
vector<char> C;
vector<vector<ll>> dp;

void dfs(int cur, int parent) {
    ll val1 = 1, val2 = 1;
    for (int child: G[cur]) {
        if (child == parent) continue;
        dfs(child, cur);
        if (C[cur] == 'a') {
            val1 *= (dp[child][0] + dp[child][2]);
            val2 *= (dp[child][0] + dp[child][1] + dp[child][2] * 2);
            
        }
        else {
            val1 *= (dp[child][1] + dp[child][2]);
            val2 *= (dp[child][0] + dp[child][1] + dp[child][2] * 2);
        }
        val1 %= mod;
        val2 %= mod;
    }
    if (C[cur] == 'a') {
        dp[cur][0] = val1;
        dp[cur][2] = (val2 - val1 + mod) % mod;
    }
    else {
        dp[cur][1] = val1;
        dp[cur][2] = (val2 - val1 + mod) % mod;
    }
}

int main() {
    int N; cin >> N;
    C.resize(N);
    rep(i, N) cin >> C[i];
    G.resize(N);
    rep(i, N - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dp.assign(N, vector<ll>(3, 0));

    dfs(0, -1);
    cout << dp[0][2] << endl;
}
