#include <bits/stdc++.h>

#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    const int MX = 500005;
    fenwick_tree<ll> tc(MX), ts(MX);
    rep(i, n) tc.add(a[i], 1), ts.add(a[i], a[i]);

    rep(i, q) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            --x;
            tc.add(a[x], -1);
            ts.add(a[x], -a[x]);
            a[x] = y;
            tc.add(a[x], 1);
            ts.add(a[x], a[x]);
        } else {
            ll ans = 0;
            if (x > y) {
                ans = (ll)n * x;
            } else {
                ans += tc.sum(0, x) * x;
                ans += ts.sum(x, y);
                ans += tc.sum(y, MX) * y;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
