#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    ll A, B; cin >> A >> B;
    ll divisor = GCD(A, B);
    ll maximum = 1e18;
    if ((A / divisor) > maximum / B) {
        cout << "Large" << endl;
    }
    else {
        cout << A * (B / divisor) << endl;
    }
    return 0;
}
