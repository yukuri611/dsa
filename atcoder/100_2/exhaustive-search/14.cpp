#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    ll res = LLONG_MAX;
    rep(i, (1 << N)) {
        int cnt = __builtin_popcount(i);
        if (cnt != K) continue;

        ll total_cost = 0;
        ll prev_max = 0;
        rep(j, N) {
            if ((i >> j) & 1) {
                ll currHeight = A[j];
                if (currHeight < prev_max + 1) currHeight = prev_max + 1;
                ll cost = max(currHeight - A[j], 0LL);
                total_cost += cost;
                prev_max = currHeight;
            } else {
                prev_max = max(prev_max, A[j]);
            }
        }
        res = min(res, total_cost);
    }
    cout << res << endl;
    return 0;
}
