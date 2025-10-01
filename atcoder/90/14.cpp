#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll res = 0;
    rep(i, N) { res += abs(A[i] - B[i]); }
    cout << res << endl;
    return 0;
}
