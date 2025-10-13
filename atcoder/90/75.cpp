#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll countFactor(ll n) {
    ll res = 0;
    ll curr = n;
    for (ll i = 2; i * i <= n; ++i) {
        while (curr % i == 0) {
            curr /= i;
            res++;
        }
    }
    if (curr > 1) res++;
    return res;
}

int main() {
    ll N;
    cin >> N;

    ll cnt = countFactor(N);
    int res = 0;
    ll curr = 1;
    while (curr < cnt) {
        curr *= 2;
        res++;
    }

    cout << res << endl;
    return 0;
}
