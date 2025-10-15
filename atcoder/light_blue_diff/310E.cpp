#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string S;
    cin >> S;

    ll res = 0;
    ll dp0 = 0, dp1 = 0;
    rep(i, N) {
        ll nextDp0, nextDp1;
        if (S[i] == '0') {
            nextDp0 = 1;
            nextDp1 = dp0 + dp1;
        } else {
            nextDp0 = dp1;
            nextDp1 = dp0 + 1;
        }
        dp0 = nextDp0;
        dp1 = nextDp1;
        res += dp1;
    }

    cout << res << endl;
}
