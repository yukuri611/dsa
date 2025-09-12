#include <bits/stdc++.h>

using namespace std;
using LL = long long;
int mod = 1000000007;

LL power(LL m, int n) {
  LL res = 1;
  while(n > 0) {
    if (n&1) res = (res * m) % mod;
    m = (m * m) % mod;
    n >>= 1;
  }

  return res;
}

int main() {
  int N, Q; cin >> N >> Q;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  vector<int> C(Q + 2);
  C[0] = 0; C[Q + 1] = 0;
  for (int i = 1; i < Q + 1; ++i) {
    cin >> C[i];
    C[i]--;
  }

  vector<int> street(N,0); //street[i] = i-1とiを結ぶ道
  for (int i = 1; i < Q+2; ++i) {
    street[min(C[i], C[i-1]) + 1]++;
    street[max(C[i], C[i-1]) + 1]--;
  }
  for (int i = 1; i < N; ++i) {
    street[i] += street[i-1];
  }

  LL res = 0;
  for (int i = 1; i < N; ++i) {
    if (street[i] != 0) {
      res = (res + power(A[i-1], A[i]) * street[i]) % mod;
    }
  }
  cout << res << endl;
  return 0;

}
