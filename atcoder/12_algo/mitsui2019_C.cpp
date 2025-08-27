#include <iostream>
#include <vector>

using namespace std;

int main() {
  int X;
  cin >> X;
  vector<bool> dp(100106);
  dp[0] = 1;

  for (int i = 0; i <= X; i++) {
    if(dp[i]) for (int j = 0; j < 6; ++j) dp[i + j + 100] = 1;
  }
  cout << dp[X] << endl;
  return 0;
}
