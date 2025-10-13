#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    map<ll, vector<ll>> Map;
    rep(i, N) { Map[A[i]].push_back(i); }

    ll res = 0;
    for (auto [n, v] : Map) {
        int sz = v.size();
        vector<ll> B;
        rep(i, sz) { B.push_back(v[i] - i); }
        vector<ll> sumB(sz + 1, 0);
        rep(i, sz) { sumB[i + 1] = sumB[i] + B[i]; }
        for (int j = 0; j < sz; ++j) {
            res += B[j] * j - sumB[j];
        }
    }

    cout << res << endl;
    return 0;
}
