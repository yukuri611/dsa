#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N + 1);
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int c = 0;
        for (int j : G[i]) {
            if (j < i) c++;
        }
        if (c == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
