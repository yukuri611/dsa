#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) { cin >> A[i] >> B[i]; }

    vector<ll> candidate;
    rep(i, N) {
        candidate.push_back(A[i]);
        candidate.push_back(B[i]);
    }

    ll res = LLONG_MAX;
    rep(i, candidate.size()) {
        rep(j, candidate.size()) {
            ll start = candidate[i];
            ll end = candidate[j];
            ll total_dist = 0;
            rep(k, N) {
                ll d1 = abs(A[k] - start) + abs(B[k] - end);
                ll d2 = abs(B[k] - start) + abs(A[k] - end);
                ll dist = min(d1, d2) + abs(A[k] - B[k]);
                total_dist += dist;
            }
            res = min(res, total_dist);
        }
    }

    cout << res << endl;
    return 0;
}
