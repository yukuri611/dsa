#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll mod = 1e9 + 7;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> X(Q), Y(Q), Z(Q), W(Q);
    rep(i, Q) {
        cin >> X[i] >> Y[i] >> Z[i] >> W[i];
        X[i]--;
        Y[i]--;
        Z[i]--;
    }

    int M = 60;
    ll res = 1;
    rep(i, M) {
        // 現在ビットiを考える。
        int cnt = 0;
        rep(j, (1 << N)) {
            bool valid = true;
            rep(k, Q) {
                int x = X[k], y = Y[k], z = Z[k];
                ll w = W[k];
                if ((((j >> x) & 1) | ((j >> y) & 1) | ((j >> z) & 1)) !=
                    ((w >> i) & 1)) {
                    valid = false;
                    break;
                }
            }
            if (valid) cnt++;
        }
        res *= cnt;
        res %= mod;
    }

    cout << res << endl;
    return 0;
}
