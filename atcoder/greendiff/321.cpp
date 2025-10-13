#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
#define int ll
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    ll P;
    cin >> N >> M >> P;
    vector<ll> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];

    sort(B.begin(), B.end());

    vector<ll> sumB(M + 1);
    sumB[0] = 0;
    rep(i, M) { sumB[i + 1] = sumB[i] + B[i]; }

    ll res = 0;
    rep(i, N) {
        int j = upper_bound(B.begin(), B.end(), P - A[i]) - B.begin();
        res += j * A[i] + sumB[j];
        res += (M - j) * P;
    }

    cout << res << endl;
    return 0;
}
