#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned N, T, M;
    cin >> N >> T >> M;
    vector<unsigned> hate(N, 0);
    rep(i, M) {
        unsigned a, b;
        cin >> a >> b;
        a--;
        b--;
        hate[b] |= (1 << a);
    }

    vector<bool> possibleTeam((1 << N), false);
    for (unsigned i = 0; i < (1 << N); ++i) {
        unsigned mask = 0;
        for (int j = 0; j < N; ++j) {
            if (i >> j & 1) mask |= hate[j];
        }
        if (!(i & mask)) possibleTeam[i] = true;
    }

    vector dp((1 << N), vector<unsigned>(T + 1, 0));
    dp.front().front() = 1;

    for (unsigned i = 0; i < 1 << N; ++i) {
        unsigned c = i | (i + 1);
        for (unsigned j = c; j < 1 << N; (++j) |= c) {
            unsigned newTeam = i ^ j;
            if (!possibleTeam[newTeam]) continue;
            for (unsigned k = 0; k < T; ++k) {
                dp[j][k + 1] += dp[i][k];
            }
        }
    }

    cout << dp.back().back() << endl;
    return 0;
}
