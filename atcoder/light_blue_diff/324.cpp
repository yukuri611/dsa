#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        pq1;
    rep(i, N) {
        ll t, d;
        cin >> t >> d;
        pq1.push({t, d});
    }

    ll res = 0;
    ll prevTime = -1;
    priority_queue<ll, vector<ll>, greater<ll>> pq2;
    while (!pq1.empty() || !pq2.empty()) {
        if (pq2.empty()) {
            auto [t, d] = pq1.top();
            pq1.pop();
            prevTime = t;
            pq2.push(t + d);
        }
        while (!pq1.empty() && prevTime == pq1.top().first) {
            auto [t, d] = pq1.top();
            pq1.pop();
            pq2.push(t + d);
        }
        ll outtime = pq2.top();
        pq2.pop();
        if (prevTime <= outtime) {
            prevTime += 1;
            res++;
        }
    }

    cout << res << endl;
    return 0;
}
