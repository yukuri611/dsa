#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

ll countPrimeFactor(ll N) {
    ll res = 0;
    ll remain = N;
    for (ll p = 2; remain > 1 && p * p <= N; ++p) {
        while (remain % p == 0) {
            res++;
            remain /= p;
        }
    }
    if (remain != 1) res++;
    return res;
}

int main() {
    ll N;
    cin >> N;

    ll c = countPrimeFactor(N);
    int ans = 0;
    int curr = 1;
    while (curr < c) {
        ans++;
        curr *= 2;
    }

    cout << ans << endl;
}
