#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    ll N, K, P;
    cin >> N >> K >> P;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    int mid = N / 2;

    vector<vector<ll>> vec1(mid + 1), vec2(N - mid + 1);
    for (int s = 0; s < (1 << mid); ++s) {
        ll sum = 0;
        ll c = 0;
        rep(j, mid) {
            if ((s >> j) & 1) {
                sum += A[j];
                c++;
            }
        }
        if (sum <= P) vec1[c].push_back(sum);
    }
    for (int s = 0; s < (1 << (N - mid)); ++s) {
        ll sum = 0;
        ll c = 0;
        rep(j, N - mid) {
            if ((s >> j) & 1) {
                sum += A[mid + j];
                c++;
            }
        }
        if (sum <= P) vec2[c].push_back(sum);
    }

    rep(i, N - mid + 1) { sort(vec2[i].begin(), vec2[i].end()); }
    ll res = 0;
    for (int c1 = 0; c1 <= mid; ++c1) {
        int c2 = K - c1;
        if (c2 < 0 || c2 > (N - mid)) continue;

        for (ll sum1 : vec1[c1]) {
            auto it = upper_bound(vec2[c2].begin(), vec2[c2].end(), P - sum1);
            res += (it - vec2[c2].begin());
        }
    }
    cout << res << endl;
    return 0;
}
