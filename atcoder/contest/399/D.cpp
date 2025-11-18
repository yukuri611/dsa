#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (int i = 0; i < N; ++i)
using ll = long long;

void solve() {
    int N;
    cin >> N;
    int N2 = N * 2;
    vector<int> A(N2);
    rep(i, N2) cin >> A[i];
    rep(i, N2) A[i]--;

    vector<vector<int>> is(N);
    rep(i, N2) is[A[i]].push_back(i);

    set<pair<int, int>> cand;
    rep(i, N2 - 1) {
        int x = A[i], y = A[i + 1];
        if (x == y) continue;
        if (x > y) swap(x, y);
        cand.insert({x, y});
    }

    ll res = 0;
    for (auto [x, y] : cand) {
        int xl = is[x][0], xr = is[x][1];
        int yl = is[y][0], yr = is[y][1];
        if (xl + 1 == xr) continue;
        if (yl + 1 == yr) continue;
        if (abs(xl - yl) == 1 && abs(xr - yr) == 1) res++;
    }

    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    rep(ti, T) solve();
    return 0;
}
