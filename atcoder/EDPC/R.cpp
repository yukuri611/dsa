#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

vector<vector<ll>> matrix_mul(vector<vector<ll>> &A, vector<vector<ll>> &B) {
  int m = A.size(); int n = A[0].size(); int l = B[0].size();
  vector<vector<ll>> res(m, vector<ll>(l,0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < l; ++j) {
      for (int k = 0; k < n; ++k) {
        res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % mod;
      }
    }
  }
  return res;
}
vector<vector<ll>> matrix_pow(vector<vector<ll>> &A, ll K) {
  int N = A.size();
  vector<vector<ll>> res(N, vector<ll>(N, 0));
  for (int i = 0; i < N; ++i) res[i][i] = 1;
  while(K > 0) {
    if (K & 1) res = matrix_mul(res, A);
    A = matrix_mul(A, A);
    K >>= 1;
  }
  return res;
}

int main() {
  ll N, K; cin >> N >> K;
  vector<vector<ll>> A(N, vector<ll>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> A[i][j];
    }
  }

  auto A_K = matrix_pow(A, K);
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      res = (res + A_K[i][j]) % mod;
    }
  }
  
  cout << res << endl;
}
