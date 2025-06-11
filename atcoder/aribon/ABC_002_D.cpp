#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int N, M, x[66], y[66];
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> x[i] >> y[i];
  }

  unordered_map<int, unordered_set<int>> map;
  for (int i = 0; i < M; i++) {
    map[x[i]].insert(y[i]);
    map[y[i]].insert(x[i]);
  }
  
  int res = 1;
  for (int mask = 0; mask < (1 << N); ++mask) {
    vector<int> teams;
    for (int i = 0; i < N; i++) {
      if((mask >> i) & 1) {
        teams.push_back(i+1);
      }
    }
    int length = teams.size();
    bool isconnected = true;
    for (int i = 0; i < length; i++) {
      if (!isconnected) {
        break;
      }
      for (int j = i + 1; j < length; j++) {
        if (!isconnected) {
          break;
        }
        if (!map.count(teams[i]) or !map[teams[i]].count(teams[j])) {
          isconnected = false;
        }
      }
    }
    if (isconnected) {
      res = max(res, length);
    }
  }

  cout << res << endl;
  return 0;
}
