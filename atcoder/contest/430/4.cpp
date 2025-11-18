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

    int r = 1;
    ll res = 0;
    rep(l, N) {
        while (r < N && (l == r || A[r] > A[r - 1])) {
            r++;
        }
        res += (r - l);
        if (l == r) r++;
    }

    cout << res << endl;
    return 0;
}
