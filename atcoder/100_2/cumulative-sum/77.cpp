#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> S(n);
    S[0] = 0;
    for (int i = 1; i < n; ++i) {
        cin >> S[i];
        S[i] += S[i - 1];
    }

    vector<int> A(m);
    rep(i, m) cin >> A[i];

    int cur = 0;
    ll ans = 0;
    rep(i, m) {
        int nxt = cur + A[i];
        ans += abs(S[nxt] - S[cur]);
        ans %= 100000;
        cur = nxt;
    }

    cout << ans << endl;
    return 0;
}
