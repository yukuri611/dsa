#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<ll> X(N);
    rep(i, N) cin >> X[i];

    map<ll, ll> dist;
    set<ll> S;
    ll res = 0;
    rep(i, N) {
        ll x = X[i];
        auto it = S.upper_bound(x);

        auto pre = prev(it);
        if ()
            if (it == S.begin()) {
                ll curr_d = *S.begin() - x;
                if (dist[*S.begin()] > curr_d) {
                    res -= (dist[*S.begin()] - curr_d);
                    dist[*S.begin()] = curr_d;
                }
            } else {
            }
    }
}
