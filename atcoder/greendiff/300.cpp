#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> primes;

void findPrime(ll N) {
    vector<bool> visited(sqrt(N) + 1, false);
    for (ll i = 2; i * i < N; ++i) {
        if (visited[i] == false) {
            primes.push_back(i);
            for (ll j = 1; i * j < sqrt(N) + 1; ++j) {
                visited[i * j] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N;
    cin >> N;
    findPrime(N);

    sort(primes.begin(), primes.end());
    int sz = primes.size();

    int res = 0;
    rep(i, sz) {
        for (int j = i + 1; j < sz; ++j) {
            ll a = primes[i], b = primes[j];
            if (N < a * a * b) break;
            for (int k = j + 1; k < sz; ++k) {
                ll c = primes[k];
                if (N < (a * a * b * c)) break;
                if (N < (a * a * b * c * c)) break;
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}
