#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll H, W, K, V; cin >> H >> W >> K >> V;
  vector<vector<ll>> A(H, vector<ll>(W));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> A[i][j];
    }
  }

  vector<vector<ll>> sum(H + 1, vector<ll>(W + 1,0));
  for (int i = 1; i < H + 1; ++i) {
    for (int j = 1; j < W + 1; ++j) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + A[i - 1][j - 1];
    }
  }
  ll area = 0;
  for (int a = 0; a < H; ++a) {
    for (int b = 0; b < W; ++b) {
      for (int c = a; c < H; ++c) {
        int l = b; int r = W;
        while(l < r) {
          int mid = (r - l) / 2 + l;
          ll curr_sum = sum[c + 1][mid + 1] - sum[c + 1][b] - sum[a][mid + 1] + sum[a][b];
          ll curr_cost = curr_sum + (c - a + 1) * (mid - b + 1) * K;
          if (curr_cost <= V) {
            l = mid + 1;
          }
          else {
            r = mid;
          }
        }
        int d = l - 1;
        ll curr_area = (c - a + 1) * (d - b + 1);
        area = max(area, curr_area);
      }
    }
  }

  cout << area << endl;
  return 0;

}
