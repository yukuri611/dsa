#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int d, n, m; cin >> d >> n >> m;
  vector<int> D(n-1);
  for (int i = 0; i < n-1; ++i) cin >> D[i];
  vector<int> k(m);
  for (int i = 0; i < m; ++i) cin >> k[i];

  D.push_back(0);
  D.push_back(d);
  sort(D.begin(), D.end());

  int res = 0;
  for (int i = 0; i < m; ++i) {
    int pos = lower_bound(D.begin(), D.end(), k[i]) - D.begin();
    int closest;
    if (pos == 0) closest = D[pos] - k[i];
    else closest = min(D[pos] - k[i], k[i] - D[pos - 1]);
    res += closest;
  }

  cout << res << endl;
  return 0;

}
