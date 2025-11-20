#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    vector<int> A_unique = A;
    sort(A_unique.begin(), A_unique.end());
    A_unique.erase(unique(A_unique.begin(), A_unique.end()), A_unique.end());
    vector<int> B(N);
    rep(i, N) {
        int a = A[i];
        auto id = lower_bound(A_unique.begin(), A_unique.end(), a);
        B[i] = id - A_unique.begin();
    }

    rep(i, N) cout << B[i] << endl;
    return 0;
}
