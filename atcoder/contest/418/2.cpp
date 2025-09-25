#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string S; cin >> S;

  double res = 0;
  for (int i = 0; i < S.size(); ++i) {
    for (int j = i; j < S.size(); ++j) {
      string subS = S.substr(i, j - i + 1);
      if (subS[0] != 't' || subS[subS.size()-1] != 't' || subS.size() < 3) {
        continue;
      }

      double c = 0;
      for (char ch: subS) {
        if (ch == 't') c++;
      }

      res = max(res, (c - 2) / (subS.size() - 2));
    }
  }

  cout << fixed << setprecision(9) << res << endl;
  return 0;

}
