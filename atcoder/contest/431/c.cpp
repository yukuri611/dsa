#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    vector<ll> H(N);
    map<ll, ll> B;
    rep(i, N) cin >> H[i];
    rep(i, M) {
        ll b;
        cin >> b;
        B[b]++;
    }
    sort(H.begin(), H.end());

    int cnt = 0;
    rep(i, N) {
        ll h = H[i];
        auto it = B.lower_bound(h);
        if (it == B.end()) break;
        ll b = it->first;
        B[b]--;
        if (B[b] == 0) {
            B.erase(b);
        }
        cnt++;
    }

    if (cnt >= K) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
