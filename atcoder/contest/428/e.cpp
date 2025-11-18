#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int N;
    cin >> N;
    vector<vector<int>> to(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    using P = pair<int, int>;
    vector<P> ans(N);
    auto dfs = [&](auto dfs, int sv, int v, int p = -1, int d = 0) -> P {
        ans[v] = max(ans[v], P(d, sv));
        P res(d, v);
        for (int u : to[v]) {
            if (u != p) {
                res = max(res, dfs(dfs, sv, u, v, d + 1));
            }
        }
        return res;
    };

    int a = dfs(dfs, 0, 0).second;
    int b = dfs(dfs, a, a).second;
    dfs(dfs, b, b);

    rep(i, N) cout << ans[i].second + 1 << endl;
    return 0;
}
