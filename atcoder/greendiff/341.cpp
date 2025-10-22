// LCMの倍数はすべて使用不可。LCMを除くK番目の割り切れる数を求めよという問題。
// 倍数の探索方法。二分探索。
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

ll GCD(ll n, ll m) {
    if (n < m) return GCD(m, n);
    while (m > 0) {
        ll nextN = m;
        ll nextM = n % m;
        n = nextN;
        m = nextM;
    }
    return n;
}

ll LCM(ll n, ll m) { return n / GCD(n, m) * m; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M, K;
    cin >> N >> M >> K;

    ll lcm = LCM(N, M);

    ll l = 0;
    ll r = 1e18;
    while (r - l > 1) {
        ll mid = (r - l) / 2 + l;
        ll count = mid / N + mid / M - 2 * (mid / lcm);
        if (count >= K)
            r = mid;
        else
            l = mid;
    }

    cout << r << endl;
    return 0;
}
