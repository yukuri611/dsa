#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    vector<int> A_uni = A;
    sort(A_uni.begin(), A_uni.end());
    A_uni.erase(unique(A_uni.begin(), A_uni.end()), A_uni.end());
    vector<int> B(n);
    rep(i, n) B[i] =
        lower_bound(A_uni.begin(), A_uni.end(), A[i]) - A_uni.begin();

    rep(i, n) cout << B[i] << endl;
    return 0;
}
