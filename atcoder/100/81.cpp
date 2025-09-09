#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> imos(1000002,0);
  for (int i = 0; i < n; ++i) {
    int a, b; cin >> a >> b;
    imos[a] += 1;
    imos[b + 1] -= 1;
  }
  int res = imos[0];
  for (int i = 1; i < imos.size(); ++i) {
    imos[i] += imos[i-1];
    res = max(res, imos[i]);
  }
  cout << res << endl;
  return 0;
}
