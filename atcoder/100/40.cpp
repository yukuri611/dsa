#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> decided(N + 1, -1);
  for (int i = 0; i < K; ++i) {
    int day, pasta; cin >> day >> pasta;
    decided[day] = pasta;
  }

  vector<vector<long long>> dp(4,vector<long long>(4, 0)); //
  if (decided[1] != -1 && decided[2] != -1) {dp[decided[1]][decided[2]] = 1;}
  else if (decided[1] != -1) {for (int i = 1; i <= 3; ++i) dp[decided[1]][i] = 1;}
  else if (decided[2] != -1) {for (int i = 1; i <= 3; ++i) dp[i][decided[2]] = 1;}
  else for (int i = 1; i <= 3; ++i) {for (int j = 1; j <= 3; ++j) dp[i][j] = 1;}
  for (int day = 3; day <= N; ++day) {
    vector<vector<long long>> nextDp(4,vector<long long>(4, 0)); 
    for (int curr = 1; curr <= 3; ++curr) {
      for (int prev = 1; prev <= 3; ++prev) {
        long long sum = 0;
        for (int i = 1; i <= 3; ++i) sum += dp[i][prev];
        if (curr == prev) sum -= dp[prev][prev];
        nextDp[prev][curr] = sum % 10000;
      }
    }
    if (decided[day] != -1) {
      int pasta = decided[day];
      if (pasta == 1) {
        for (int i = 1; i <= 3; ++i) {
          nextDp[i][2] = 0;
          nextDp[i][3] = 0;
        }
      }
      else if (pasta == 2) {
        for (int i = 1; i <= 3; ++i) {
          nextDp[i][3] = 0;
          nextDp[i][1] = 0;
        }
      }
      else {
        for (int i = 1; i <= 3; ++i) {
          nextDp[i][1] = 0;
          nextDp[i][2] = 0;
        }
      }
    }
    dp = nextDp;
  }

  long long total = 0;
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
      total += dp[i][j];
    }
  }
  cout << total % 10000 << endl;
  return 0;
}
