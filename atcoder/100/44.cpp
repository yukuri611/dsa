#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> N(200,0);
  vector<int> N_odd;
  for (int i = 1; i < 200; ++i) {
    int curr = i * (i + 1) * (i + 2) / 6;
    N[i] = curr;
    if (curr % 2) N_odd.push_back(curr);
  }

  vector<int> dp1(pow(10,6) + 1, INT_MAX);
  dp1[0] = 0;
  for (int i = 0; i < pow(10,6) + 1; ++i) {
    for (int n: N) {
      if (i + n < pow(10, 6) + 1) dp1[i + n] = min(dp1[i + n], dp1[i] + 1);
    }
  }

  vector<int> dp2(pow(10,6) + 1, INT_MAX);
  dp2[0] = 0;
  for (int i = 0; i < pow(10,6) + 1; ++i) {
    for (int n: N_odd) {
      if (i + n < pow(10, 6) + 1) dp2[i + n] = min(dp2[i + n], dp2[i] + 1);
    }
  }

  vector<pair<int, int>> res_list;
  while (true) {
    int target; cin >> target;
    if (target == 0) break;
    res_list.push_back({dp1[target], dp2[target]});
  }
  for (auto res: res_list) cout << res.first << " " << res.second << endl;
  return 0;
}
