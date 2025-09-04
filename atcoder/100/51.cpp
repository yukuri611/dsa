#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
  int N; cin >> N;
  string S; cin >> S;
  vector<vector<LL>> dp(N, vector<LL>((1 << 3)));
  map<char, int> m{{'J',0},{'O', 1}, {'I', 2}};

  for (int i = 0; i < N; ++i) {
    char c = S[i];
    if (i == 0) {
      for (int j = 0; j < (1 << 3); ++j) {
        int temp = ((j & (1 << m[c])) & (j & (1 << 0)));
        dp[i][j] = ((j & (1 << m[c])) != 0) && ((j & (1 << 0)) != 0); //責任者とJが参加
      }
    }
    else {
      for (int j = 0; j < (1 << 3); ++j) {
        if ((j & (1 << m[c])) == 0) continue; //責任者不在
        for (int prev = 0; prev < (1 << 3); ++prev) {
          if ((prev & j) == 0) continue; //前日の参加者ゼロ
          dp[i][j] += dp[i-1][prev];
          dp[i][j] %= 10007;
        }
      }
    }
  }

  int sum = 0;
  for (int i = 0; i < (1 << 3); ++i) {
    sum += dp[N-1][i];
    sum %= 10007;
  }
  cout << sum << endl;
  return 0;
}
