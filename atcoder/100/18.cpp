#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n; cin >> n;
  vector<long long> S(n);
  for (int i = 0; i < n; ++i) cin >> S[i];
  int q; cin >> q;
  vector<long long> T(q);
  for (int i = 0; i < q; ++i) cin >> T[i];

  int res = 0;
  for (long long t: T) {
    auto pos = lower_bound(S.begin(), S.end(), t);
    if (pos != S.end() && *pos == t) res++;
  }

  cout << res << endl;
  return 0;
}
