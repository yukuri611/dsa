#include <iostream>
#include <unordered_set>
#define LEN 10

using namespace std;

struct pair_hash {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto h1 = hash<T1>{}(p.first);
    auto h2 = hash<T2>{}(p.second);
    return h1 ^ (h2 << 1);
  }
};

void dfs(int i, int j, char grid[LEN][LEN], unordered_set<pair<int, int>, pair_hash> &visited) {
  int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
  for (auto& dir: directions) {
    int ni = i + dir[0];
    int nj = j + dir[1];
    if (0 <= ni && ni < LEN && 0 <= nj && nj < LEN && visited.count({ni, nj}) == 0 && grid[ni][nj] == 'o') {
      visited.insert({ni, nj});
      dfs(ni, nj, grid, visited);
    }
  }
}

int main() {
  char grid[LEN][LEN];
  int land_area = 0;
  for (int i = 0; i < LEN; i++) {
    for (int j = 0; j < LEN; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'o') {
        land_area += 1;
      }
    }
  }

  for (int i = 0; i < LEN; i++) {
    for (int j = 0; j < LEN; j++) {
      unordered_set<pair<int, int>, pair_hash> visited;
      visited.insert({i,j});
      dfs(i, j, grid, visited);
      if (visited.size() == land_area + 1) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  
  cout << "NO" << endl;
  return 0;
}
