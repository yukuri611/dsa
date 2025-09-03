#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

  vector<int> tetra;
  vector<int> tetra_odd;
  for (int i = 1; i < 200; ++i) {
    tetra.push_back(i * (i + 1) * (i + 2) / 6);
    if ((i * (i + 1) * (i + 2) / 6) % 2 == 1) tetra_odd.push_back(i * (i + 1) * (i + 2) / 6);
  }

  vector<int> dp1(1000001, INT_MAX);
  dp1[0] = 0;
  for (int i = 1; i < dp1.size(); ++i) {
    for (int j = 0; j < tetra.size(); ++j) {
      if (tetra[j] > i) continue;
      dp1[i] = min(dp1[i], dp1[i - tetra[j]] + 1);
    }
  }
  vector<int> dp2(1000001, INT_MAX);
  dp2[0] = 0;
  for (int i = 1; i < dp2.size(); ++i) {
    for (int j = 0; j < tetra_odd.size(); ++j) {
      if (tetra_odd[j] > i) continue;
      dp2[i] = min(dp2[i], dp2[i - tetra_odd[j]] + 1);
    }
  }
  
  vector<pair<int,int>> res_list;
  while (true) {
    int N; cin >> N;
    if (N == 0) break;
    res_list.push_back({dp1[N], dp2[N]});
  }
  for (auto p: res_list) {
    cout << p.first << " " << p.second << endl;
  }
  return 0;
}
