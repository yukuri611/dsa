#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    int M = 1e5 + 1;
    vector<bool> included(M, false);

    int r = 0;
    int res = 0;
    rep(l, N) {
        while (r < N && !included[A[r]]) {
            included[A[r]] = true;
            r++;
        }
        res = max(r - l, res);
        included[A[l]] = false;
    }
    cout << res << endl;
    return 0;
}
