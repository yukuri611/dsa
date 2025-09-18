#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N, Q; cin >> N >> Q;
  vector<ll>A(N + 1), B(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  for (int i = 1; i <= N; ++i) {
    cin >> B[i];
  }

  ll total = 0;
  for (int i = 1; i <= N; ++i) {
    total += min(A[i], B[i]);
  }

  vector<ll> res_list;
  for (int i = 0; i < Q; ++i) {
    char c; cin >> c;
    ll X, V; cin >> X >> V;
    ll prev_min = min(A[X], B[X]);
    if (c == 'A') {
      A[X] = V;
      ll curr_min = min(A[X], B[X]);
      total += (curr_min - prev_min);
      res_list.push_back(total);
    }
    else {
      B[X] = V;
      ll curr_min = min(A[X], B[X]);
      total += (curr_min - prev_min);
      res_list.push_back(total);
    }
  }

  for (ll res: res_list) cout << res << endl;
  return 0 ;
}
