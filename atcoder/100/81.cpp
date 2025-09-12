#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> imos(1e6 + 2);
  for (int i = 0; i < n; ++i) {
    int a, b; cin >> a >> b;
    imos[a] += 1; imos[b + 1]-= 1;
  }
  for (int i = 0; i < 1e6+1; ++i) {
    imos[i + 1] += imos[i];
  }
  int res = 0;
  for (int i = 0; i < 1e6 + 1; ++i) {
    res = max(res, imos[i]);
  }
  cout << res << endl;
  return 0;
}
