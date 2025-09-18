#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
  int N, K; cin >> N >> K;
  vector<ll> x1(N), y1(N), d1(N), x2(N), y2(N), d2(N);
  set<ll> setX, setY, setD;
  for (int i = 0; i < N; ++i) {
    cin >> x1[i] >> y1[i] >> d1[i] >> x2[i] >> y2[i] >> d2[i];
    setX.insert(x1[i]); setX.insert(x2[i]); setY.insert(y1[i]); setY.insert(y2[i]); setD.insert(d1[i]); setD.insert(d2[i]);
  } 
  vector<ll> uX(setX.begin(), setX.end());
  vector<ll> uY(setY.begin(), setY.end());
  vector<ll> uD(setD.begin(), setD.end());

  int X, Y, Z; X = uX.size(); Y = uY.size(); Z = uD.size();
  vector<vector<vector<ll>>> grid(X, vector<vector<ll>>(Y, vector<ll>(Z, 0)));
  for (int i = 0; i < N; ++i) {
    int cx1 = lower_bound(uX.begin(), uX.end(), x1[i]) - uX.begin();
    int cx2 = lower_bound(uX.begin(), uX.end(), x2[i]) - uX.begin();
    int cy1 = lower_bound(uY.begin(), uY.end(), y1[i]) - uY.begin();
    int cy2 = lower_bound(uY.begin(), uY.end(), y2[i]) - uY.begin();
    int cd1 = lower_bound(uD.begin(), uD.end(), d1[i]) - uD.begin();
    int cd2 = lower_bound(uD.begin(), uD.end(), d2[i]) - uD.begin();
    grid[cx1][cy1][cd1] += 1;
    grid[cx1][cy2][cd1] += -1;
    grid[cx2][cy1][cd1] += -1;
    grid[cx2][cy2][cd1] += 1;
    grid[cx1][cy1][cd2] += -1;
    grid[cx1][cy2][cd2] += 1;
    grid[cx2][cy1][cd2] += 1;
    grid[cx2][cy2][cd2] += -1;
  }

  for (int x = 0; x < X; ++x) {
    for (int d = 0; d < Z; ++d) {
      for (int y = 1; y < Y; ++y) {
        grid[x][y][d] += grid[x][y-1][d];
      }
    }
  }
  for (int y = 0; y < Y; ++y) {
    for (int d = 0; d < Z; ++d) {
      for (int x = 1; x < X; ++x) {
        grid[x][y][d] += grid[x - 1][y][d];
      }
    }
  }
  for (int x = 0; x < X; ++x) {
    for (int y = 0; y < Y; ++y) {
      for (int d = 1; d < Z; ++d) {
        grid[x][y][d] += grid[x][y][d-1];
      }
    }
  }
  ll total_volume = 0;
  for (int x = 0; x < X - 1; ++x) {
    for (int y = 0; y < Y - 1; ++y) {
      for (int d = 0; d < Z - 1; ++d) {
        if (grid[x][y][d] >= K) {
          ll dx = uX[x + 1] - uX[x];
          ll dy = uY[y + 1] - uY[y];
          ll dz = uD[d + 1] - uD[d];
          total_volume += dx * dy * dz; 
        }
      }
    }
  }

  cout << total_volume << endl;
  return 0;

}
