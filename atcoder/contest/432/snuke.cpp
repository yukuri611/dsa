#include <bits/stdc++.h>

#include <atcoder/segtree>
using namespace atcoder;
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

struct S {
    ll count;
    ll sum;
};

S op(S a, S b) { return {a.count + b.count, a.sum + b.sum}; }

S e() { return {0, 0}; }

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    const int MX = 500005;

    segtree<S, op, e> seg(MX);

    rep(i, n) {
        S current = seg.get(a[i]);
        seg.set(a[i], {current.count + 1, current.sum + a[i]});
    }

    rep(i, q) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            --x;
            int old_val = a[x];
            int new_val = y;

            S current_old = seg.get(old_val);
            seg.set(old_val,
                    {current_old.count - 1, current_old.sum - old_val});

            S current_new = seg.get(new_val);
            seg.set(new_val,
                    {current_new.count + 1, current_new.sum + new_val});

            a[x] = new_val;
        } else {
            ll ans = 0;
            if (x > y) {
                ans = (ll)n * x;
            } else {
                S s1 = seg.prod(0, x);
                ans += s1.count * x;

                S s2 = seg.prod(x, y);
                ans += s2.sum;

                S s3 = seg.prod(y, MX);
                ans += s3.count * y;
            }
            cout << ans << endl;
        }
    }

    return 0;
}
