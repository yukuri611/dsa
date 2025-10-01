#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

ll GCD(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int main() {
    ll A, B, C;
    cin >> A >> B >> C;
    ll D = GCD(A, B);
    ll E = GCD(B, C);
    ll F = GCD(D, E);
    ll ans = A / F - 1 + B / F - 1 + C / F - 1;
    cout << ans << endl;
    return 0;
}
