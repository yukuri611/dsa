#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)
ll mod = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    int m = 6;
    vector<int> sumA(N, 0);
    rep(i, N) {
        rep(j, m) {
            int a;
            cin >> a;
            sumA[i] += a;
        }
    }

    ll res = 1;
    rep(i, N) { res = (res * sumA[i]) % mod; }
    cout << res << endl;
    return 0;
}
