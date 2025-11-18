#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> X(N);
    rep(i, Q) cin >> X[i];

    vector<ll> res_list;
    rep(i, Q) {
        ll x = X[i];
        int r = 0;
        ll sum = 0;
        ll res = 0;
        rep(l, N) {
            while (r < N && sum + A[r] <= x) {
                sum += A[r];
                r++;
            }

            res += (r - l);
            if (l == r)
                r++;
            else
                sum -= A[l];
        }
        res_list.push_back(res);
    }

    for (ll res : res_list) cout << res << endl;
    return 0;
}
