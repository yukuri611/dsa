#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

#include <atcoder/all>
using namespace atcoder;

using S = ll;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }
int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    vector<int> A(N);
    rep(i, N) cin >> H[i];
    rep(i, N) cin >> A[i];

    vector<S> vec(N + 1);
    segtree<S, op, e> seg(vec);
    rep(i, N) {
        int h = H[i], a = A[i];
        ll cur_val = seg.prod(0, h);
        cur_val += a;
        seg.set(h, cur_val);
    }

    cout << seg.prod(0, N + 1) << endl;
    return 0;
}
