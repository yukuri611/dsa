#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

vector<ll> factors;

void findFactors(ll N) {
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            factors.push_back(i);
            if (N / i != i) factors.push_back(N / i);
        }
    }
}

int main() {
    ll K;
    cin >> K;
    findFactors(K);
    sort(factors.begin(), factors.end());

    ll res = 0;
    for (int i = 0; i < factors.size(); ++i) {
        for (int j = i; j < factors.size(); ++j) {
            ll a = factors[i];
            ll b = factors[j];
            if ((K / a) < b) continue;
            if (K % (a * b) != 0) continue;
            ll c = (K / (a * b));
            if (b <= c) res++;
        }
    }

    cout << res << endl;
    return 0;
}
