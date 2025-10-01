#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, R; cin >> N >> R;
  vector<int> L(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> L[i];
  }

  int res = 0;
  int l = R + 1;
  for (int i = 1; i <= R; ++i) {
    if (L[i] == 0) {
      l = i;
      break;
    }
  }
  int c = 0;
  if (l != R + 1){
    for (int i = l + 1; i <= R; ++i) {
      if (L[i] == 1) c++;
    }
    c += R - l + 1;
    res += c;
  }
  int r = R;
  for (int i = N; i > R; --i) {
    if (L[i] == 0) {
      r = i;
      break;
    }
  }
  c = 0;
  if (r != R) {
    for (int i = R + 1; i <= r - 1; ++i) {
      if (L[i] == 1) c++;
    }
    c += r - R;
    res += c;
  }
  
  cout << res <<endl;

  return 0;
}
