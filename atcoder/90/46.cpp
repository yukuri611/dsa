#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N;
    cin >> N;
    vector<ll> A(46, 0), B(46, 0), C(46, 0);
    rep(i, N) {
        int a;
        cin >> a;
        A[(a % 46)]++;
    }
    rep(i, N) {
        int b;
        cin >> b;
        B[(b % 46)]++;
    }
    rep(i, N) {
        int c;
        cin >> c;
        C[(c % 46)]++;
    }

    ll res = 0;
    rep(a, 46) {
        rep(b, 46) {
            int c = (46 - ((a + b) % 46)) % 46;
            res += A[a] * B[b] * C[c];
        }
    }

    cout << res << endl;
    return 0;
}
