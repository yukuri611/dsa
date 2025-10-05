#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

vector<vector<int>> G;
vector<int> C;
int dfs(int curr, int pre) {
    C[curr] = 1;
    for (int child : G[curr]) {
        if (child == pre) continue;
        C[curr] += dfs(child, curr);
    }
    return C[curr];
}

int main() {
    int N;
    cin >> N;
    G.resize(N + 1);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    C.resize(N + 1, 0);
    dfs(1, -1);

    ll res = 0;
    for (int i = 1; i <= N; ++i) {
        for (int child : G[i]) {
            ll r = min(C[child], C[i]);
            res += r * (N - r);
        }
    }
    cout << res / 2 << endl;
    return 0;
}
