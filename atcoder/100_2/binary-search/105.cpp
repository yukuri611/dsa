#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, K, L, R;
    cin >> N >> K >> L >> R;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    int M = N / 2;
    vector<vector<ll>> sum1(M + 1);
    rep(i, (1 << M)) {
        ll sum = 0;
        int cnt = 0;
        rep(j, M) {
            if ((i >> j) & 1) {
                sum += A[j];
                cnt++;
            }
        }
        sum1[cnt].push_back(sum);
    }

    vector<vector<ll>> sum2(N - M + 1);
    rep(i, (1 << (N - M))) {
        ll sum = 0;
        int cnt = 0;
        rep(j, N - M) {
            if ((i >> j) & 1) {
                sum += A[j + M];
                cnt++;
            }
        }
        sum2[cnt].push_back(sum);
    }

    rep(i, sum2.size()) { sort(sum2[i].begin(), sum2[i].end()); }

    ll res = 0;
    rep(i, sum1.size()) {
        int remain_cnt = K - i;
        if (remain_cnt >= sum2.size()) continue;
        for (ll s1 : sum1[i]) {
            auto& vec = sum2[remain_cnt];
            auto r = upper_bound(vec.begin(), vec.end(), R - s1);
            auto l = lower_bound(vec.begin(), vec.end(), L - s1);
            ll cnt = r - l;
            res += cnt;
        }
    }

    cout << res << endl;
    return 0;
}
