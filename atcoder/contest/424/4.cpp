#include <bits/stdc++.h>

using namespace std;

int main() {
  int T; cin >> T;
  vector<int> res_list(T);
  for (int l = 0; l< T; ++l) {
    int H, W; cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
      cin >> S[i];
    }

    vector<vector<int>> dp(H, vector<int>((1 << W), INT_MAX)); //1は黒、0は白
    for (int j = 0; j < (1 << W); ++j) {
      int c = 0; 
      for (int k = 0; k < W; ++k) {
        if (S[0][k] == '.' && ((j >> k) & 1) == 1) {
          c = INT_MAX;
          break;
        }
        else if (S[0][k] == '#' && ((j >> k) & 1) == 0) {
          c++;
        }
      }
      dp[0][j] = c;
    }
    for (int i = 1; i < H; ++i) {
      for (int j = 0; j < (1 << W); ++j) {
        int c = 0; 
        for (int k = 0; k < W; ++k) {
          if (S[i][k] == '.' && ((j >> k) & 1) == 1) {
            c = INT_MAX;
            break;
          }
          else if (S[i][k] == '#' && ((j >> k) & 1) == 0) {
            c++;
          }
        }
        if (c == INT_MAX) {
          dp[i][j] = INT_MAX;
          continue;
        }
        else {
          for (int jprev = 0; jprev < (1 << W); ++jprev) {
            if (dp[i-1][jprev] == INT_MAX) continue;
            bool hasSquare = false;
            for (int k = 0; k < W - 1; ++k) {
              if (((j >> k) & 1) && ((jprev >> k) & 1) && ((j >> (k + 1)) & 1) && ((jprev >> (k + 1)) & 1)) {
                hasSquare = true;
              }
            }
            if (!hasSquare) {
              dp[i][j] = min(dp[i][j], dp[i-1][jprev] + c);
            }
          }      
        }
      }
    }

    res_list[l] = (*(min_element(dp[H - 1].begin(), dp[H - 1].end())));
  }

  for (int res: res_list) cout << res << endl;
  return 0;
}
