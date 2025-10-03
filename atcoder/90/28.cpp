#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N;
    cin >> N;
    vector<vector<int>> cnt(1001, vector<int>(1001, 0));
    rep(i, N) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        cnt[lx][ly] += 1;
        cnt[lx][ry] += -1;
        cnt[rx][ly] += -1;
        cnt[rx][ry] += 1;
    }

    rep(x, 1000) {
        rep(y, 1001) { cnt[x + 1][y] += cnt[x][y]; }
    }
    rep(y, 1000) {
        rep(x, 1001) { cnt[x][y + 1] += cnt[x][y]; }
    }

    vector<int> ans(N + 1);
    rep(x, 1001) {
        rep(y, 1001) { ans[cnt[x][y]]++; }
    }
    for (int i = 1; i <= N; ++i) cout << ans[i] << endl;
    return 0;
}
