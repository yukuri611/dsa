#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<ll>> matrix_mul(const vector<vector<ll>> &A, const vector<vector<ll>> &B) {
  int N = A.size(); int M = B.size(); int L = B[0].size();
  vector<vector<ll>> res(N, vector<ll>(L, 0));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < L; ++j) {
      for (int k = 0; k < M; ++k) {
        res[i][j] ^= (A[i][k] & B[k][j]);
      }
    }
  }
  return res;
}

vector<vector<ll>> matrix_pow(const vector<vector<ll>> &A, ll n) {
  if (n == 0) {
    ll N = A.size();
    vector<vector<ll>> res(N, vector<ll>(N,0));
    for (int i = 0; i < N; ++i) {
      res[i][i] =  ~0LL;
    }
    return res;
  }
  if (n % 2) {
    auto B = matrix_pow(A, (n-1) / 2);
    auto C = matrix_mul(B, B);
    return matrix_mul(A, C);
  }
  else {
    auto B = matrix_pow(A, n/2);
    return matrix_mul(B, B);
  }
}

int main() {
  long long K, M; cin >> K >> M;
  vector<ll> A(K), C(K);
  for (int i = 0; i < K; ++i) {
    cin >> A[i];
  }
  for (int i = 0; i < K; ++i) {
    cin >> C[i];
  }

  if (M <= K) {
    cout << A[M - 1] << endl;
    return 0;
  }

  vector<vector<ll>> B(K, vector<ll>(K,0));
  for (int i = 0; i < K; ++i) {
    B[0][i] = C[i];
  }
  for (int i = 1; i < K; ++i) {
    B[i][i-1] = ~0LL;
  }

  auto D = matrix_pow(B, M-K);

  vector<vector<ll>> initial_matrix(K, vector<ll>(1));
  for (int i = 0; i < K; ++i) {
    initial_matrix[i][0] = A[K - 1 - i];
  }

  auto res = matrix_mul(D, initial_matrix);
  cout << res[0][0] << endl;
  return 0;


}
