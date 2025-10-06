#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

vector<vector<int>> G;
vector<ll> cnts;
ll dfs(int u, int prev) {
    ll cnt = 1;
    for (int v: G[u]) {
        if (v == prev) continue;
        cnt += dfs(v, u);
    }
    cnts[u] = cnt;
    return cnt;
}

int main() {
    int N; cin >> N;
    G.resize(N + 1);
    rep(i, N-1) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    cnts.resize(N + 1);
    dfs(1, 0);

    ll res = 0;
    for(int u = 1; u <= N; ++u) {
        for(int v: G[u]) {
            ll c = min(cnts[u], cnts[v]);
            res += (c * (N - c));
        }
    }
    res /= 2;

    cout << res << endl;
    return 0;


}
