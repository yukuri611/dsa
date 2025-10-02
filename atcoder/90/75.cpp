#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll count_pf(ll n) {
    ll ans = 0;
    double M = sqrt(n);
    for (ll i = 2; i <= M && n > 1; ++i) {
        while (n % i == 0) {
            ans++;
            n /= i;
        }
    }
    if (n != 1) ans++;
    return ans;
}

int main() {
    ll N;
    cin >> N;
    ll pf_count = count_pf(N);
    ll ans = 0;
    while (pf_count > pow(2, ans)) ans++;
    cout << ans << endl;
    return 0;
}
