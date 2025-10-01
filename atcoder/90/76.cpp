#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> sumA(2 * N, 0);
    rep(i, N) { sumA[i + 1] = sumA[i] + A[i]; }
    for (int i = N; i < 2 * N; ++i) {
        sumA[i + 1] = sumA[i] + A[i - N];
    }

    if (sumA[N] % 10 != 0) {
        cout << "No" << endl;
        return 0;
    }

    ll target = sumA[N] / 10;
    rep(i, N) {
        auto it = lower_bound(&sumA[i], &sumA[i + N], target + sumA[i]);
        if (*(it)-sumA[i] == target) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
