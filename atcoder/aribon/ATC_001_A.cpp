#include <iostream>
#include <vector>
using namespace std;

bool dfs(int i, int j, vector<vector<char>> &grid);
int main()
{
  int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      cin >> grid[i][j];
    }
  }

  int s_i, s_j;
  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < W; j++)
    {
      if (grid[i][j] == 's')
      {
        s_i = i;
        s_j = j;
      }
    }
  }

  bool res = dfs(s_i, s_j, grid);
  if (res)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}

bool dfs(int i, int j, vector<vector<char>> &grid)
{
  if (grid[i][j] == 'g')
  {
    return true;
  }

  pair<int, int> directions[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  bool res = false;
  for (pair<int, int> direction : directions)
  {
    int i_next = i + direction.first;
    int j_next = j + direction.second;
    if (i_next < 0 or i_next >= grid.size() or j_next < 0 or j_next >= grid[0].size() or grid[i_next][j_next] == '#' or grid[i_next][j_next] == 'T')
    {
      continue;
    }
    char temp = grid[i][j];
    grid[i][j] = 'T';
    if (dfs(i_next, j_next, grid))
    {
      grid[i_next][j_next] = temp;
      return true;
    }
    grid[i + direction.first][j + direction.second] = temp;
  }
  return false;
}
