#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
  LL H, W, K, V; cin >> H >> W >> K >> V;
  vector<vector<int>> A(H, vector<int>(W));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> A[i][j];
    }
  }
  vector<vector<LL>> sum(H + 1, vector<LL>(W + 1, 0));
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
      sum[i][j] = A[i - 1][j - 1] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
    }
  }
  int res = 0;
  for (int a = 0; a < H; ++a) {
    for (int b = 0; b < W; ++b) {
      for (int c = a; c < H; ++c) {
        //二分探索でdを求める。
        int l = b-1; int r = W;
        while (l + 1< r) {
          int mid = (l + r) / 2;
          LL curr_sum = sum[c + 1][mid + 1] - sum[c + 1][b] - sum[a][mid + 1] + sum[a][b];
          int area = (c - a + 1) * (mid - b + 1);
          LL total_cost = curr_sum + area * K;
          if (total_cost <= V) l = mid;
          else r = mid;
        }
        int area = (c - a + 1) * (l - b + 1);
        res = max(res, area);
      }
    }
  }

  cout << res << endl;
  return 0;
}
