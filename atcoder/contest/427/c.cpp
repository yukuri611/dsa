#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N, vector<int>(N, 0));
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u][v] = 1;
        G[v][u] = 1;
    }

    int res = 1000;
    rep(s, (1 << N)) {
        set<int> Set1;
        set<int> Set2;
        rep(i, N) {
            if ((s >> i) & 1)
                Set1.insert(i);
            else
                Set2.insert(i);
        }
        int cut = 0;
        for (int u : Set1) {
            rep(v, N) {
                if (Set1.find(v) == Set1.end()) continue;
                if (G[u][v]) cut++;
            }
        }
        for (int u : Set2) {
            rep(v, N) {
                if (Set2.find(v) == Set2.end()) continue;
                if (G[u][v]) cut++;
            }
        }
        res = min(res, cut);
    }
    res /= 2;
    cout << res << endl;
    return 0;
}
