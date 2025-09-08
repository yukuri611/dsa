#include <bits/stdc++.h>

using namespace std;

int K = 1000000007;

long long calc_distance(long long a, long long b) {
  // a ^ bを計算
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % K;
    a = (a * a) % K;
    b >>= 1;
  }
  return res;
}
int main() {
  int N, Q; cin >> N >> Q;
  vector<int> A(N);
  for (int i = 1; i < N + 1; ++i) cin >> A[i];
  vector<int> C(Q + 2);
  C[0] = 1; C[Q + 1] = 1;
  for (int i = 1; i < Q + 1; ++i) cin >> C[i];

  long long total = 0; 
  for (int i = 1; i < Q + 2; ++i) {
    if (C[i - 1] <= C[i]) {
      for (int j = C[i - 1] + 1; j <= C[i]; ++j) {
        total = (total + calc_distance(A[j-1], A[j])) % K;
      }
    }
    else {
      for (int j = C[i] + 1; j <= C[i - 1]; ++j) {
        total = (total + calc_distance(A[j-1], A[j])) % K;
      }
    }
  }
  cout << total << endl;
}
