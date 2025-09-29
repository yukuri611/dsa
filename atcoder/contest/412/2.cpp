#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  string T;
  cin >> T;

  for (int i = 0; i < S.size(); ++i) {
    if (S[i] >= 'A' && S[i] <= 'Z') {
      if (i == 0) continue;
      bool valid = false;
      for (int j = 0; j < T.size(); ++j) {
        if (S[i - 1] == T[j]) {
          valid = true;
          break;
        }
      }
      if (!valid) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
