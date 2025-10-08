#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<ll> primes;

void calcprimes(ll n) {
    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = 2; i * j <= n; ++j) {
                isPrime[i * j] = false;
            }
        }
    }

    for (int i = 2; i < n + 1; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    calcprimes(288675);
    cout << primes.size() << endl;
    return 0;
}

// int main() {
//     ll N; cin >> N;

//     calcprimes(N);

//     int M = primes.size();

//     set<ll> s;

//     rep(a, M) {
//         for (int b = a + 1; b < M; ++b) {
//             for (int c = b + 1; c < M; ++c) {
//                 ll cur = a * a * b * c * c;
//                 if (cur > N) continue;
//                 s.insert(cur);
//             }
//         }
//     }

//     cout << s.size() << endl;
//     return 0;
// }
