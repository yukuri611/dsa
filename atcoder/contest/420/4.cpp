#include <bits/stdc++.h>

using namespace std;

int H, W;
vector<string> A;
vector<vector<pair<int, int>>> dist;

vector<int> di = {1,0,-1,0};
vector<int> dj = {0,1,0,-1};

void bfs(int s_i, int s_j) {
  queue<tuple<int, int, char>> q; //i , j , f
  q.push(make_tuple(s_i, s_j, 'o'));
  dist[s_i][s_j].first = 0;
  while(!q.empty()) {
    auto t = q.front();
    q.pop();
    int i = get<0>(t); int j = get<1>(t); char f = get<2>(t);
    int curr_d = (f == 'o') ? dist[i][j].first: dist[i][j].second;
    if (f == 'o') {
      for (int k = 0; k < 4; ++k) {
        int ni = i + di[k]; int nj = j + dj[k];
        if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
        int next_d = curr_d + 1;
        if (A[ni][nj] == '?') {
          if (dist[ni][nj].second > next_d) {
            dist[ni][nj].second = next_d;
            q.push(make_tuple(ni, nj, 'x'));
          }
        }
        if (A[ni][nj] == '.' || A[ni][nj] == 'o' || A[ni][nj] == 'G' || A[ni][nj] == 'S') {
          if (dist[ni][nj].first > next_d) {
            dist[ni][nj].first = next_d;
            q.push(make_tuple(ni, nj, 'o'));
          }
        }
      }
    }
    else {
      for (int k = 0; k < 4; ++k) {
        int ni = i + di[k]; int nj = j + dj[k];
        if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
        int next_d = curr_d + 1;
        if (A[ni][nj] == '?') {
          if (dist[ni][nj].first > next_d) {
            dist[ni][nj].first = next_d;
            q.push(make_tuple(ni, nj, 'o'));
          }
        }
        if (A[ni][nj] == '.' || A[ni][nj] == 'x' || A[ni][nj] == 'G' || A[ni][nj] == 'S') {
          if (dist[ni][nj].second > next_d) {
            dist[ni][nj].second = next_d;
            q.push(make_tuple(ni, nj, 'x'));
          }
        }
      }
    }
  }
}

int main() {
  cin >> H >> W;
  dist.assign(H, vector<pair<int,int>>(W, {INT_MAX, INT_MAX}));
  A.resize(H);
  for (int i = 0; i < H; ++i) {
    cin >> A[i];
  }

  int s_i, s_j, g_i, g_j;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      if (A[i][j] == 'S') {
        s_i = i;
        s_j = j;
      }
      else if (A[i][j] == 'G') {
        g_i = i;
        g_j = j;
      }
    }
  }

  bfs(s_i, s_j);
  int res = min(dist[g_i][g_j].first, dist[g_i][g_j].second);
  if (res == INT_MAX) cout << -1 << endl;
  else cout << res << endl;
  return 0;
}
