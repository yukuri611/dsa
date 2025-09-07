#include <bits/stdc++.h>

using namespace std;
using LL = long long;
int main() {
  int T; cin >> T;
  vector<LL> res_list;
  for (int _ = 0; _ < T; ++_) {
    LL a, b, c; cin >> a >> b >> c;
    LL maximum = min(a, c);
    if (b > maximum) {
      LL res = maximum;
      res_list.push_back(res);
      continue;
    }
    else if (a + b + c >= 3 * maximum) {
      LL res = maximum;
      res_list.push_back(res);
      continue;
    }
    else {
      LL res = (a + b + c) / 3;
      res_list.push_back(res);
    }
  }

  for (LL res: res_list) cout << res << endl;
  return 0;
}
