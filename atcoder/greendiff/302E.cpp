#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int N;
    cin >> N;
    int Q;
    cin >> Q;

    vector<set<int>> G(N);

    int cnt = N;
    rep(i, Q) {
        int f;
        cin >> f;
        if (f == 1) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            G[u].insert(v);
            G[v].insert(u);
            if (G[u].size() == 1) cnt--;
            if (G[v].size() == 1) cnt--;
        } else {
            int v;
            cin >> v;
            v--;
            for (int u : G[v]) {
                G[u].erase(v);
                if (G[u].size() == 0) cnt++;
            }
            if (G[v].size() > 0) cnt++;
            G[v].clear();
        }
        cout << cnt << endl;
    }

    return 0;
}
