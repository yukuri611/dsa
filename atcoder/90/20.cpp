#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll power(ll a, ll n) {
    ll res = 1;
    while(n > 0) {
        if (n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int main() {
    long double a, b, c;
    cin >> a >> b >> c;

    // 計算
    if (a < pow(c, b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
