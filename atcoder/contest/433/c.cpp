#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    string S;
    cin >> S;
    int N = S.size();

    ll ans = 0;
    rep(i, N - 1) {
        if (S[i + 1] - S[i] == 1) {
            int d = 0;
            while (i - d >= 0 && i + 1 + d < N && S[i - d] == S[i] &&
                   S[i + 1 + d] == S[i + 1]) {
                d++;
            }
            ans += d;
        }
    }
    cout << ans << endl;
}
