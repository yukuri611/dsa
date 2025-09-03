#include <iostream>
#include <vector>

using namespace std;

int main() {
  int q; cin >> q;
  vector<int> res;
  for (int _ = 0; _ < q; ++_) {
    string X, Y; cin >> X >> Y;
    int lx, ly; lx = X.length(); ly = Y.length();

    vector<int> dp(ly + 1,0);
    for (int i = 1; i < lx + 1; ++i){
      int prev = 0;
      for (int j = 1; j < ly + 1; ++j) {
        int temp = dp[j];
        if (X[i-1] == Y[j-1]) {
          dp[j] = prev + 1;
        } 
        else {
          dp[j] = max(dp[j-1], dp[j]);
        }
        prev = temp;
      }
    }
    res.push_back(dp[ly]);
  }
  for (int r: res) cout << r << endl;
  return 0;
}
