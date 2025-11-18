#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    int Q;
    cin >> Q;
    vector<ll> X(Q);
    rep(i, Q) cin >> X[i];

    rep(i, Q) {
        ll x = X[i];
        int r = 0;
        ll sum = 0;
        ll res = 0;
        rep(l, N) {
            while (r < N && sum + A[r] < x) {
                sum += A[r];
                r++;
            }
            res += N - r;
            if (l == r)
                r++;
            else
                sum -= A[l];
        }
        cout << res << endl;
    }
}
