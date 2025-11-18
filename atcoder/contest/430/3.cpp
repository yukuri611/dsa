#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<ll> S(N);
    rep(i, N) cin >> S[i];

    if (count(S.begin(), S.end(), 0)) {
        cout << N << endl;
        return 0;
    }

    int r = 0;
    ll total = 1;
    int res = 0;
    rep(l, N) {
        while (r < N && total * S[r] <= K) {
            total *= S[r];
            r++;
        }
        res = max(res, r - l);
        if (l == r)
            r++;
        else
            total /= S[l];
    }
    cout << res << endl;
    return 0;
}
