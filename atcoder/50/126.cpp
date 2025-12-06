#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

vector<int> Colors;
bool isBipartite(vector<vector<int>>& G) {
    int N = G.size();
    queue<int> q;
    q.push(0);
    Colors[0] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : G[u]) {
            if (Colors[v] != -1) {
                if (Colors[v] != 1 - Colors[u]) return false;
            } else {
                Colors[v] = 1 - Colors[u];
                q.push(v);
            }
        }
    }
    return true;
}
int main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    Colors.assign(N, -1);

    ll ans = 0;
    if (isBipartite(G)) {
        ll cnt_b = 0, cnt_w = 0;
        rep(i, N) {
            if (Colors[i] == 0)
                cnt_b++;
            else
                cnt_w++;
            ans = cnt_b * cnt_w - M;
        }
    } else {
        ans = (N * (N - 1)) / 2 - M;
    }
    cout << ans << endl;
    return 0;
}
