#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;

    vector<ll> P(N);
    rep(i, N) cin >> P[i];
    vector<ll> L(M), V(M);
    rep(i, M) cin >> L[i];
    rep(i, M) cin >> V[i];
    vector<pair<ll, ll>> combined(M);

    sort(P.begin(), P.end());
    rep(i, M) combined[i] = {L[i], V[i]};
    sort(combined.begin(), combined.end());

    priority_queue<ll> pq;  // 現在使用することのできるクーポンの割引値段を確保

    ll res = 0;
    int index = 0;
    for (ll p : P) {
        while (index < M && combined[index].first <= p) {
            pq.push(combined[index].second);
            index++;
        }
        ll d = 0;
        if (!pq.empty()) {
            d = pq.top();
            pq.pop();
        }
        res += p - d;
    }

    cout << res << endl;
    return 0;
}
