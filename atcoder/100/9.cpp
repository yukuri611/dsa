#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int m; cin >> m;
  vector<pair<int, int>> stellar(m);
  for(int i = 0; i < m; ++i) {
    int x, y; cin >> x >> y; 
    stellar[i] = {x, y};
  }
  int n; cin >> n;
  vector<pair<int, int>> all_star(n);
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    all_star[i] = {x, y};
  }

  pair<int, int> res;
  for (int i = 0; i < n; ++i) {
    int dx, dy;
    dx = all_star[i].first - stellar[0].first; 
    dy = all_star[i].second - stellar[0].second;
    int valid = true;
    for (int j = 1; j < m; ++j) {
      int x, y;
      x = stellar[j].first + dx;
      y = stellar[j].second + dy;
      pair<int, int> curr_grid = {x,y};
      if (find(all_star.begin(), all_star.end(), curr_grid) == all_star.end()){
        valid = false;
        break;
      }
    }
    if (valid) {
      res = {dx, dy};
    }
  }
  cout << res.first << " " << res.second << endl;
  return 0;

}
