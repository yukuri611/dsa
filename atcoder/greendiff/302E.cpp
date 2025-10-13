#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    vector<set<int>> G(N + 1);

    int c = N;
    rep(i, Q) {
        int f;
        cin >> f;
        if (f == 1) {
            int u, v;
            cin >> u >> v;
            G[u].insert(v);
            G[v].insert(u);
            if (G[u].size() == 1) c--;
            if (G[v].size() == 1) c--;
        } else {
            int v;
            cin >> v;
            for (int u : G[v]) {
                G[u].erase(v);
                if (G[u].size() == 0) c++;
            }
            if (G[v].size() != 0) {
                G[v].clear();
                c++;
            }
                }
        cout << c << endl;
    }

    return 0;
}
