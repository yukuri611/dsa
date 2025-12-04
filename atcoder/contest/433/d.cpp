#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    vector<vector<ll>> as(11);
    rep(i, N) as[to_string(a[i]).size()].push_back(a[i]);

    ll ans = 0;
    ll ten = 1;
    rep(i, 11) {
        unordered_map<ll, int> Map;
        rep(j, N) Map[(((-a[j] % M * ten % M) % M) + M) % M]++;
        for (auto a : as[i]) {
            ans += Map[a % M];
        }
        ten *= 10;
    }

    cout << ans << endl;
}
