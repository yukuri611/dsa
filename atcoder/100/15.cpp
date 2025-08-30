#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
  int N; cin >> N;
  vector<pair<int, int>> grid(N);
  for (int i = 0; i < N; ++i) {
    int x, y; cin >> x >> y;
    grid[i] = {x, y};
  }

  vector<int> p = {0, 1, 2, 3, 4, 5, 6, 7};
  double total = 0;
  int count = 0;
  do {
    double dist = 0;
    for (int i = 0; i < N-1; ++i) {
      int dx = grid[p[i + 1]].first - grid[p[i]].first;
      int dy = grid[p[i + 1]].second - grid[p[i]].second;
      dist += pow(pow(dx, 2) + pow(dy, 2), 0.5);
    }
    total += dist;
    count++;
  } while(next_permutation(p.begin(), p.begin() + N));

  cout << fixed << setprecision(12) << total / count << endl;
  return 0; 
}
