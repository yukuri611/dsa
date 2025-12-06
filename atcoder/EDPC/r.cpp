#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int mod = 1e9 + 7;

vector<vector<int>> matrix_mul(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size(), m = A[0].size(), l = B[0].size();
    vector<vector<int>> ans(n, vector<int>(l));
    rep(i, n) {
        rep(j, l) {
            rep(k, m) { ans[i][j] = (ans[i][j] + (ll)A[i][k] * B[k][j]) % mod; }
        }
    }
    return ans;
}

vector<vector<int>> matrix_pow(vector<vector<int>> A, ll n) {
    int sz = A.size();
    vector<vector<int>> ans(sz, vector<int>(sz));
    rep(i, sz) ans[i][i] = 1;
    while (n > 0) {
        if (n & 1) ans = matrix_mul(ans, A);
        A = matrix_mul(A, A);
        n >>= 1;
    }
    return ans;
}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<vector<int>> A(N, vector<int>(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    auto A_K = matrix_pow(A, K);
    vector<vector<int>> X(N, vector<int>(1, 1));
    auto ans_vec = matrix_mul(A_K, X);
    int ans = 0;
    rep(i, N) {
        ans += ans_vec[i][0];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
