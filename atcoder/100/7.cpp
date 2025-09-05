#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n;
  vector<vector<int>> V(n, vector<int>(2));
  set<pair<int, int>> S;
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    V[i] = {x,y};
    S.insert({x,y});
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      int x1, x2, y1, y2; x1 = V[i][0]; x2 = V[j][0]; y1 = V[i][1]; y2 = V[j][1];
      int x3, x4, y3, y4; 
      x3 = x1 + y2 - y1; y3 = y1 + x1 - x2; x4 = x2 + y2 - y1; y4 = y2 + x1 - x2;
      if (!S.count({x3,y3}) || !S.count({x4,y4})) continue;
      int area = pow(x2 - x1, 2) + pow(y2 - y1, 2);
      res = max(res, area);
    }
  }
  cout << res << endl;
  return 0;
}
