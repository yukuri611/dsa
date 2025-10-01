#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)
#define all(A) A.begin(), A.end()

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> points;
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        points.push_back(b);
        points.push_back(a - b);
    }

    sort(points.begin(), points.end());
    ll res = 0;
    rep(i, K) { res += points[points.size() - 1 - i]; }
    cout << res << endl;
    return 0;
}
