
#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

auto op(ll a, ll b) { return min(a, b); }

auto e() { return LLONG_MAX; }

int main() {
    ll N, x;
    cin >> N >> x;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    segtree<ll, op, e> st(A);
    ll res = LLONG_MAX;
    rep(k, N) {
        ll ans = 0;
        rep(i, N) {
            if (i - k < 0) {
                auto min1 = st.prod(0, i + 1);
                auto min2 = st.prod(N + i - k, N);
                ans += min(min1, min2);
            } else {
                auto min1 = st.prod(i - k, i + 1);
                ans += min1;
            }
        }
        ans += x * k;
        res = min(res, ans);
    }

    cout << res << endl;
}
