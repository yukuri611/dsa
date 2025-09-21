#include <bits/stdc++.h>

using namespace std;

int main() {
  string s; cin >> s;
  string t; cin >> t;
  int N = s.length();
  int M = t.length();
  vector<string> dp(M + 1, "");
  for (int i = 1; i <= N; ++i) {
    string prev = dp[0];
    for (int j = 1; j <= M; ++j) {
      string temp = dp[j];
      if (s[i - 1] == t[j - 1]) {
        dp[j] = prev + s[i - 1];
      }
      else if (dp[j - 1].length() > dp[j].length()){
        dp[j] = dp[j - 1];
      }
      prev = temp;
    }
  }
  cout << dp[M] << endl;
  return 0;
}
