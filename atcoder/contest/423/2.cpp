#include <bits/stdc++.h>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> L(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> L[i];
  }

  int a = N;
  for (int i = 1; i <= N; ++i) {
    if (L[i] == 1) {
      //鍵がかかってる
      a = i - 1;
      break;
    }
  }

  int b = 0;
  for (int i = N; i >= 1; --i) {
    if (L[i] == 1) {
      //鍵がかかってる
      b = i;
      break;
    }
  }

  int res = max(b - a - 1, 0);
  cout << res << endl;
  return 0;
}
