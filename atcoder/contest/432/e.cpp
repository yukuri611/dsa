#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

struct S {
    ll sum, cnt;
};
S op(S a, S b) { return {a.sum + b.sum, a.cnt + b.cnt}; }
S e() { return {0, 0}; }

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> Com(Q), X(Q), Y(Q);
    rep(i, Q) {
        cin >> Com[i] >> X[i] >> Y[i];
        if (Com[i] == 1) {
            X[i]--;
        }
    }

    int M = 5e5 + 1;
    vector<S> vec(M, {0, 0});
    rep(i, N) {
        vec[A[i]].sum += A[i];
        vec[A[i]].cnt++;
    }
    segtree<S, op, e> seg(vec);
    rep(i, Q) {
        int com = Com[i], x = X[i], y = Y[i];
        if (com == 1) {
            S cur = seg.get(A[x]);
            seg.set(A[x], {cur.sum - A[x], cur.cnt - 1});
            A[x] = y;
            cur = seg.get(y);
            seg.set(y, {cur.sum + y, cur.cnt + 1});
        } else {
            ll sum;
            if (x < y) {
                ll l_len = seg.prod(0, x).cnt;
                ll r_len = seg.prod(y, M).cnt;
                ll sum1 = l_len * x;
                ll sum2 = r_len * y;
                ll sum3 = seg.prod(x, y).sum;
                sum = sum1 + sum2 + sum3;
            } else {
                sum = x * N;
            }
            cout << sum << endl;
        }
    }

    return 0;
}
