#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

using S = long long;
ll op(ll a, ll b) { return min(a, b); }

ll e() { return LLONG_MAX; }

int main() {
    ll N, x;
    cin >> N >> x;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    rep(i, N) A.push_back(A[i]);

    segtree<S, op, e> seg(A);
    ll res = LLONG_MAX;
    rep(magic_cnt, N) {
        ll total_cost = magic_cnt * x;
        for (int i = N; i < 2 * N; ++i) {
            ll min_cost = seg.prod(i - magic_cnt, i + 1);
            total_cost += min_cost;
        }
        res = min(total_cost, res);
    }

    cout << res << endl;
    return 0;
}
