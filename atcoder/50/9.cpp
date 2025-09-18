#include <bits/stdc++.h>

using namespace std;
using ll = long long;



ll M;

vector<vector<ll>> mul(vector<vector<ll>> A, vector<vector<ll>> B) {
  ll N = A.size(); ll K = A[0].size(); ll L = B[0].size();
  vector<vector<ll>> res(N, vector<ll>(L,0));
  if (K != B.size()) return res;
  for (ll i = 0; i < N; ++i) {
    for (ll j = 0; j < L; ++j) {
      for (ll k = 0; k < K; ++k) {
        res[i][j] += (A[i][k] * B[k][j]) % M;
      }
    }
  }
  return res; 
}

vector<vector<ll>> power_matrix(vector<vector<ll>> A, ll n) {
  if (n == 1) return A;
  if (n % 2) {
    return mul(A, power_matrix(A, n-1));
  }
  else {
    auto B = power_matrix(A, n / 2);
    return mul(B,B) ;
  }
}


int main() {
  ll N; cin >> N >> M;
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  else if (N == 2) {
    cout << 1 << endl;
    return 0;
  }
  vector<vector<ll>> fib = {{1,1},{1,0}};
  vector<vector<ll>> power = power_matrix(fib, N - 2);

  vector<vector<ll>> res = {{1},{0}};
  res = mul(power, res);
  cout << res[0][0] << endl;
  return 0;
}
