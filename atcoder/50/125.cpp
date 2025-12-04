#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

vector<vector<int>> G;

vector<int> color;

bool isBipartite(int cur) {
    for (auto nxt : G[cur]) {
        if (color[nxt] == color[cur]) {
            return false;
        }
        if (color[nxt] == -1) {
            color[nxt] = 1 - color[cur];
            if (!isBipartite(nxt)) return false;
        }
    }
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    G.resize(N);
    color.resize(N);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    fill(color.begin(), color.end(), -1);
    color[0] = 0;
    ll ans;
    if (isBipartite(0)) {
        int B = 0, W = 0;
        rep(i, N) {
            if (color[i] == 0)
                B++;
            else
                W++;
        }
        ans = (ll)B * W - M;
    } else {
        ans = ((ll)N * (N - 1)) / 2 - M;
    }
    cout << ans << endl;
    return 0;
}
