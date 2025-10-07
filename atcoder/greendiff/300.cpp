#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

vector<int> prime;
int M = 300000;

void makePrimeList() {
    vector<bool> isPrime(M + 1, true);
    for (int i = 2; i < M + 1; ++i) {
        if (isPrime[i]) {
            for (int j = 2; i * j < M + 1; ++j) {
                isPrime[i * j] = false;
            }
        }
    }

    for (int i = 2; i < M + 1; ++i) {
        if (isPrime[i]) prime.push_back(i);
    }
}

int main() {
    ll N;
    cin >> N;

    makePrimeList();

    int L = prime.size();

    ll res = 0;
    rep(i, L) {
        ll a = prime[i];
        if (a * a > N) break;
        for (int j = i + 1; j < L; ++j) {
            ll b = prime[j];
            if (a * a * b > N) break;
            ll cMax = sqrt(N / (a * a * b));
            int k =
                upper_bound(prime.begin(), prime.end(), cMax) - prime.begin();
            if (k - 1 <= j) break;
            res += (k - 1 - j);
        }
    }

    cout << res << endl;
    return 0;
}
