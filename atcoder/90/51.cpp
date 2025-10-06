#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, K; cin >> N >> K;
    ll P; cin >> P;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    int mid = N / 2;
    vector<vector<ll>> sum1(mid + 1);
    rep(s, (1 << mid)) {
        ll sum = 0;
        ll c = 0;
        rep(j, (mid)) {
            if ((s >> j) & 1) {
                sum += A[j];
                c++;
            }    
        }
        sum1[c].push_back(sum);
    }
    vector<vector<ll>> sum2(N - mid + 1);
    rep(s, (1 << (N - mid))) {
        ll sum = 0;
        ll c = 0;
        rep(j, (N - mid)) {
            if ((s >> j) & 1) {
                sum += A[j + mid];
                c++;
            }
        }
        sum2[c].push_back(sum);
    }

    rep(i, N - mid + 1) sort(sum2[i].begin(), sum2[i].end());

    ll res = 0;
    rep(c1, mid + 1) {
        int c2 = K - c1;
        if (c2 < 0) break;
        if (c2 > N - mid) continue;
        for(ll s1: sum1[c1]) {
            auto it = upper_bound(sum2[c2].begin(), sum2[c2].end(), P - s1);
            ll c = it - sum2[c2].begin();
            res += c;
        }
    }
    
    cout << res << endl;
    return 0;
}
