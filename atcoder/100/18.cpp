#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> S(n);
  for (int i = 0; i < n; ++i) cin >> S[i];
  int q; cin >> q;
  vector<int> T(q);
  for (int i = 0; i < q; ++i) cin >> T[i];

  int res = 0;
  for (int t: T) {
    auto it = lower_bound(S.begin(), S.end(), t);
    if (*it == t) res++;
  }
  cout << res << endl;
  return 0;
}
