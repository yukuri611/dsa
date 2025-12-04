#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int T;
    cin >> T;
    rep(ti, T) {
        int N, H;
        cin >> N >> H;
        vector<int> Time(N + 1), L(N + 1), U(N + 1);
        Time[0] = 0;
        L[0] = H;
        U[0] = H;
        for (int i = 1; i < N + 1; ++i) cin >> Time[i] >> L[i] >> U[i];

        bool valid = true;
        int minimum = H, maximum = H;
        for (int i = 1; i <= N; ++i) {
            int dt = Time[i] - Time[i - 1];
            maximum = min(U[i], maximum + dt);
            minimum = max(L[i], minimum - dt);
            if (minimum > maximum) {
                valid = false;
                break;
            }
        }
        if (valid)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
