#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> X(Q), Y(Q), Z(Q);
    vector<ll> W(Q);
    rep(i, Q) {
        cin >> X[i] >> Y[i] >> Z[i] >> W[i];
        X[i]--;
        Y[i]--;
        Z[i]--;
    }

    ll res = 1;
    rep(i, 60) {
        ll cnt = 0;
        rep(s, 1 << N) {
            bool valid = true;
            rep(j, Q) {
                if ((((s >> X[j]) & 1) | ((s >> Y[j]) & 1) |
                     ((s >> Z[j]) & 1)) != ((W[j] >> i) & 1)) {
                    valid = false;
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
