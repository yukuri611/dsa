#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll N; cin >> N;
  string res;
  ll total_len = 0;
  vector<char> C(N);
  vector<ll> L(N);
  for (int i = 0; i < N; ++i) cin >> C[i] >> L[i];

  for (int i = 0; i < N; ++i) {
    char c = C[i]; ll l = L[i];
    total_len += l;
    if (total_len > 100) {
      cout << "Too Long" << endl;
      return 0;
    }
    for (int j = 0; j < l; ++j) {
      res += c;
    }
  }

  cout << res << endl;
  return 0;
}
