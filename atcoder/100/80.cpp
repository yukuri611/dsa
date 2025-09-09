#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
  LL H, W, K, V; cin >> H >> W >> K >> V;
  vector<vector<LL>> A(H + 1, vector<LL>(W + 1));
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
      cin >> A[i][j];
    }
  }

  vector<vector<LL>> cost(H + 1, vector<LL> (W + 1,0)); //cost[i][j] = (1,1)から(i,jまでのコストの総和)
  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
      cost[i][j] = cost[i-1][j] + cost[i][j-1] - cost[i-1][j-1] + A[i][j];
    }
  }

  int res = 0;
  for (int a = 1; a <= H; ++a) {
    for (int b = 1; b <= W; ++b) {
      for (int c = a; c <= H; ++c) {
        //二分探索でdの取りうる最大値を求める。
        int l,r; l = b; r = W;
        int best_d = b-1;
        while(l <= r) {
          int mid = (r - l)/2 + l;
          int area =  (c - a + 1) * (mid - b + 1);
          LL curr_cost = cost[c][mid] - cost[c][b-1] - cost[a - 1][mid] + cost[a-1][b-1] + K * area;
          if (curr_cost > V) r = mid-1;
          else {
            l = mid + 1;
            best_d = mid;
          }
        }
        if (best_d >= b) res = max(res, (c - a + 1) * (best_d - b + 1));
      }
    }
  }

  cout << res << endl;
  return 0;
}
