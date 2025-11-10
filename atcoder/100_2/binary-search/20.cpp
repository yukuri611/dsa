#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<ll> H(N), S(N);
    rep(i, N) cin >> H[i] >> S[i];

    ll max_h = *max_element(H.begin(), H.end());
    ll max_s = *max_element(S.begin(), S.end());

    ll l = max_h - 1, r = max_h + max_s * N;
    while (r - l > 1) {
        ll mid = (r - l) / 2 + l;
        vector<ll> Time(N);
        rep(i, N) { Time[i] = (mid - H[i]) / S[i]; }
        sort(Time.begin(), Time.end());
        auto valid = true;
        rep(i, N) {
            if (Time[i] < i) {
                valid = false;
                break;
            }
        }

        if (valid) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << r << endl;
    return 0;
}
