#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canAttack(const vector<vector<int>> &grid, int r, int c) {
  for(int r_i = 0; r_i < 8; ++r_i) {
    if (grid[r_i][c] && r_i != r) return true;    
  }
  for (int c_i = 0; c_i < 8; ++c_i) {
    if (grid[r][c_i] && c_i != c) return true;
  }
  int r_i, c_i; r_i = r; c_i = c;
  while (r_i < 8 && r_i > -1 && c_i < 8 && c_i > -1) {
    if (grid[r_i][c_i] && (r_i != r || c_i != c)) return true;
    r_i++;
    c_i++;
  }
  r_i = r; c_i = c;
  while (r_i < 8 && r_i > -1 && c_i < 8 && c_i > -1) {
    if (grid[r_i][c_i] && (r_i != r || c_i != c)) return true;
    r_i++;
    c_i--;
  }
  r_i = r; c_i = c;
  while (r_i < 8 && r_i > -1 && c_i < 8 && c_i > -1) {
    if (grid[r_i][c_i] && (r_i != r || c_i != c)) return true;
    r_i--;
    c_i--;
  }
  r_i = r; c_i = c;
  while (r_i < 8 && r_i > -1 && c_i < 8 && c_i > -1) {
    if (grid[r_i][c_i] && (r_i != r || c_i != c)) return true;
    r_i--;
    c_i++;
  }

  return false;
}

int main() {
  int k; cin >> k;
  vector<vector<int>> grid(8, vector<int>(8,0));
  vector<pair<int,int>> queens;
  for (int i = 0; i < k; ++i) {
    int x, y; cin >> x >> y;
    grid[x][y] = 1;
    queens.push_back({x, y});
  }
  
  vector<int> permutation = {0,1,2,3,4,5,6,7};
  do {
    for (int i = 0; i < 8; ++i) {
      int r = i, c = permutation[i];
      grid[r][c] = 1;
    }
    bool valid = true;
    for (int r = 0; r < 8; ++r) {
      for (int c = 0; c < 8; ++c) {
        if (grid[r][c] && canAttack(grid, r,c)) valid = false; 
      }
    }
    if (valid) break;
    for (int i = 0; i < 8; ++i) {
      int r = i, c = permutation[i];
      grid[r][c] = 0;
    }
    for (auto queen: queens) {
      grid[queen.first][queen.second] = 1;
    }
  } while(next_permutation(permutation.begin(), permutation.begin() + 8));

  for (int r = 0; r < 8; ++r) {
    for (int c = 0; c < 8; ++c) {
      char res = grid[r][c] ? 'Q': '.';
      cout << res;
    }
    cout << endl;
  }
  return 0;
}
