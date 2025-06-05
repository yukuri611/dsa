#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<int> dp(m+1, 0);
    for (int i = 0; i <= m; i++) {
      dp[i] = m - i;
    }
    for (int i = n-1; i > -1; i--) {
      int cross = dp[m];
      dp[m] = n - i;
      for (int j = m-1; j > -1; j--) {
        int nextCross = dp[j];
        if (word1[i] == word2[j]) {
          dp[j] = cross;
        }
        else {
          dp[j] = 1 + min(min(dp[j+1], dp[j]), cross);
        }
        cross = nextCross;
      }
    }
    return dp[0];
  }
};

int main() {
  string word1 = "intention";
  string word2 = "execution";
  Solution s;
  int output = s.minDistance(word1, word2);
  cout << output << endl;
  return 0;
}
