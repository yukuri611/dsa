#include <queue>
#include <iostream>
#include <unordered_set>

#define LEN 10


using namespace std;
struct PairHash {
  template <class T1, class T2>
  std::size_t operator () (const std::pair<T1, T2>& p) const {
    auto h1 = hash<T1>{}(p.first);
    auto h2 = hash<T2>{}(p.second);
    return h1^(h2 << 1);
  }
};

bool bfs(char (&grid)[LEN][LEN], int x, int y, int land_area) {
  int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
  queue<pair<int, int>> q;
  for (auto&[di, dj]: dir) {
    int next_i = x + di;
    int next_j = y + dj;
    q.push({next_i, next_j});
  }
  unordered_set<pair<int, int>, PairHash> visited;
  
  while (!q.empty()) {
    if (visited.count(q.front())) {
      q.pop();
      continue;
    }
    auto& [i, j] = q.front();
    if (i < 0 or i > LEN - 1 or j < 0 or j > LEN - 1 or grid[i][j] == 'x') {
      q.pop();
      continue;
    }
    visited.insert({i, j});
    for (auto&[di, dj]: dir) {
      int next_i = i + di;
      int next_j = j + dj;
      q.push({next_i, next_j});
    }
    q.pop();
  }
  return visited.size() == land_area;
}

int main() {
  char grid[LEN][LEN];
  int land_area = 0;
  for (int i = 0; i < LEN; i++) {
    for (int j = 0; j < LEN; j++) {
      cin >> grid[i][j];
      land_area += (grid[i][j] == 'o');
    }
  }
  bool res = false;
  for (int i = 0; i < LEN; i++) {
    if (res) {
      break;
    }
    for (int j = 0; j < LEN; j++) {
      if (res) {
        break;
      }
      if (grid[i][j] == 'x') {
        res = bfs(grid, i, j, land_area);
      }
    }
  }

  if (res) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
  return 0;
}
