#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
#define int ll
    int N, K;
    cin >> N >> K;
    ll P;
    cin >> P;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    int mid = N / 2;
    map<int, vector<ll>> sum1;
    rep(s, (1 << mid)) {
        ll sum = 0;
        int cnt = 0;
        rep(j, mid) {
            if ((s >> j) & 1) {
                sum += A[j];
                cnt++;
            }
        }
        sum1[cnt].push_back(sum);
    }

    map<int, vector<ll>> sum2;
    rep(s, (1 << N - mid)) {
        ll sum = 0;
        int cnt = 0;
        rep(j, N - mid) {
            if ((s >> j) & 1) {
                sum += A[mid + j];
                cnt++;
            }
        }
        sum2[cnt].push_back(sum);
    }

    for (auto [cnt, v] : sum2) {
        sort(v.begin(), v.end());
    }

    ll res = 0;
    for (auto [c1, v] : sum1) {
        int c2 = K - c1;
        for (ll s1 : v) {
            auto it = upper_bound(sum2[c2].begin(), sum2[c2].end(), P - s1);
            res += (it - sum2[c2].begin());
        }
    }

    cout << res << endl;
    return 0;
}
