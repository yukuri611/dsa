#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int M = 3 * N;
    vector<int> A(M);
    rep(i, M) cin >> A[i];

    vector<int> cnt(N + 1, 0);
    vector<int> f(N + 1);
    rep(i, M) {
        int a = A[i];
        if (cnt[a] == 1) f[a] = i;
        cnt[a]++;
    }

    vector<int> res(N + 1);
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int a, int b) { return f[a] < f[b]; });

    for (int i = 1; i < N + 1; ++i) cout << res[i] << " ";
    cout << endl;
    return 0;
}
