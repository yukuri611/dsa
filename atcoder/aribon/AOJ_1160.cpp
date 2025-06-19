#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main() {
  int w, h;
  vector<int> res_list;

  while (cin >> w >> h && (w != 0 || h != 0)) {
    vector<vector<char>> grid(h, vector<char>(w,0));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> grid[i][j];
      }
    }
    
   
    int res = 0;
    int directions[8][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (grid[i][j] == '1') {
          queue<pair<int, int>> q;
          q.push({i,j});
          grid[i][j] = '2';
          while (!q.empty()) {
            pair<int, int> curr = q.front();
            for (int k = 0; k < 8; k++) {
              int ni = curr.first + directions[k][0];
              int nj = curr.second + directions[k][1];

              // Check bounds and if it's an unvisited '1'
              if (ni >= 0 && ni < h && nj >= 0 && nj < w && grid[ni][nj] == '1') {
                  grid[ni][nj] = '2'; // Mark as visited
                  q.push({ni, nj});
              }
            }
            q.pop();
          }
          res += 1;
        }
      }
    }
    res_list.push_back(res);
  }
  for (int res: res_list) {
    cout << res << endl;
  }
  return 0;
}
