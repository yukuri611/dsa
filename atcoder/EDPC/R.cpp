#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

vector<vector<ll>> matmul(vector<vector<ll>> &A, vector<vector<ll>> &B) {
  int n, m, l; n = A.size(); m = A[0].size(); l = B[0].size();
  vector<vector<ll>> res(n, vector<ll>(l, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < l; ++j) {
      for (int k = 0; k < m; ++k) {
        res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % mod;
      }
    }
  }
  return res;
} 

vector<vector<ll>> matpow(vector<vector<ll>> &A, ll n) {
  int N = A.size();
  vector<vector<ll>> res(N, vector<ll>(N,0));
  for (int i = 0; i < N; ++i) res[i][i] = 1; 

  while(n > 0) {
    if (n & 1) res = matmul(res, A);
    A = matmul(A, A);
    n >>= 1;
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
  auto B = matpow(A, K);
  ll res = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      res = (res + B[i][j]) % mod;
    }
  }
  cout << res << endl;
  return 0;
}
