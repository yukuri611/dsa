#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  #define int ll
  int N, Q; cin >> N >> Q;
  vector<ll> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  vector<ll> sumA(N + 1, 0);
  for (int i = 1; i < N + 1; ++i) {
    sumA[i] = sumA[i - 1] + A[i - 1];
  }

  vector<ll> res_list;
  int start = 0;
  for (int _ = 0; _ < Q; ++_) {
    int f; cin >> f;
    if (f == 1) {
      int c; cin >> c;
      start = (start + c) % N;
    }
    else {
      int l, r; cin >> l >> r;
      --l; --r;
      l = (start + l) % N;
      r = (start + r) % N;
      ll res;
      if (l > r) {
        res = sumA[N] - sumA[l];
        res += sumA[r + 1];
      }
      else {
        res = sumA[r + 1] - sumA[l];
      }

      res_list.push_back(res);
    }
  }

  for (ll res: res_list) cout << res << endl;

  return 0;
}
