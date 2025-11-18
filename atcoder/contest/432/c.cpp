#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    sort(A.begin(), A.end());
    ll W = Y * A[0];

    bool valid = true;
    ll total_y_cnt = 0;
    rep(i, N) {
        ll remain = Y * A[i] - W;
        if (remain % (Y - X) != 0) valid = false;
        ll cnt_x = remain / (Y - X);
        if (cnt_x > A[i]) valid = false;
        total_y_cnt += (A[i] - cnt_x);
    }

    if (valid) {
        cout << total_y_cnt << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
