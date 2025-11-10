#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<ll> P(N);
    rep(i, N) cin >> P[i];
    P.push_back(0);

    vector<ll> sum1;
    rep(i, P.size()) {
        for (int j = i; j < P.size(); ++j) {
            sum1.push_back(P[i] + P[j]);
        }
    }
    sort(sum1.begin(), sum1.end());

    ll res = 0;
    for (ll s1 : sum1) {
        auto it = upper_bound(sum1.begin(), sum1.end(), M - s1);
        int index = it - sum1.begin();
        if (index == 0) continue;
        res = max(res, s1 + sum1[index - 1]);
    }

    cout << res << endl;
    return 0;
}
