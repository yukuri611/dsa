#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i, N) for (int i = 0; i < N; ++i)

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    int c = 0;
    rep(i, N) { c += abs(A[i] - B[i]); }

    if (K < c || (K - c) % 2)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    return 0;
}
