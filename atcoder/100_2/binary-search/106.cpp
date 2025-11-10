#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, W_limit;
    cin >> N >> W_limit;
    vector<ll> V(N), W(N);
    rep(i, N) cin >> V[i] >> W[i];
    ll v_max = *max_element(V.begin(), V.end());
    ll w_max = *max_element(W.begin(), W.end());

    if (N <= 30) {
        // 半分全列挙
        map<ll, ll> map1;  // weight: value;
        rep(i, (1 << (N / 2))) {
            ll weight = 0, value = 0;
            rep(j, N / 2) {
                if ((i >> j) & 1) {
                    weight += W[j];
                    value += V[j];
                }
            }
            map1[weight] = max(map1[weight], value);
        }
        map<ll, ll> map2;  // weight: value;
        rep(i, (1 << (N - N / 2))) {
            ll weight = 0, value = 0;
            rep(j, N - N / 2) {
                if ((i >> j) & 1) {
                    weight += W[N / 2 + j];
                    value += V[N / 2 + j];
                }
            }
            map2[weight] = max(map2[weight], value);
        }

        ll prev_value = 0;
        for (auto [weight, value] : map2) {
            map2[weight] = max(prev_value, value);
            prev_value = map2[weight];
        }

        ll res = 0;
        for (auto [weight, value] : map1) {
            ll remain_weight = W_limit - weight;
            auto it = map2.upper_bound(remain_weight);
            if (it != map2.begin()) {
                ll total_value = value + (*prev(it)).second;
                res = max(res, total_value);
            }
        }

        cout << res << endl;
        return 0;
    }
    if (w_max <= 1000) {
        // wでdp
        int M = 1000 * 200;
        vector<ll> dp(M + 1, 0);
        rep(i, N) {
            vector<ll> nextDp = dp;
            rep(j, M + 1 - W[i]) {
                nextDp[j + W[i]] = max(nextDp[j + W[i]], dp[j] + V[i]);
            }
            dp = nextDp;
        }
        ll res = 0;
        rep(i, W_limit + 1) { res = max(res, dp[i]); }
        cout << res << endl;
    } else if (v_max <= 1000) {
        // vでdp
        int M = 1000 * 200;
        vector<ll> dp(M + 1, LLONG_MAX);
        dp[0] = 0;
        rep(i, N) {
            vector<ll> nextDp = dp;
            rep(j, M + 1 - V[i]) {
                if (dp[j] != LLONG_MAX)
                    nextDp[j + V[i]] = min(nextDp[j + V[i]], dp[j] + W[i]);
            }
            dp = nextDp;
        }
        ll res = 0;
        rep(i, dp.size()) {
            if (dp[i] <= W_limit) res = i;
        }
        cout << res << endl;
    }

    return 0;
}
