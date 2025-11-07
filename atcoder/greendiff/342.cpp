#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

vector<int> findOddPrimeFactors(int n) {
    vector<int> res;
    int curr = n;
    for (int i = 2; i * i <= n; ++i) {
        int c = 0;
        while (curr % i == 0) {
            curr /= i;
            c++;
        }
        if (c % 2) res.push_back(i);
    }
    if (curr > 1) res.push_back(curr);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    map<vector<int>, ll> Map;
    ll cnt0 = 0;
    rep(i, N) {
        int a = A[i];
        if (a == 0) {
            cnt0++;
            continue;
        }
        vector<int> factors = findOddPrimeFactors(a);
        Map[factors]++;
    }

    ll res = 0;
    res += cnt0 * (N - 1);
    res -= (cnt0 * (cnt0 - 1)) / 2;

    for (auto [vec, cnt] : Map) {
        res += (cnt * (cnt - 1)) / 2;
    }

    cout << res << endl;
    return 0;
}
