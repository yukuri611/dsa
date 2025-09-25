#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N, L, R; cin >> N >> L >> R;
  string S; cin >> S;

  bool f = true;
  for (int i = L-1; i < R; ++i) {
    if (S[i] != 'o') {
      f = false;
      break;
    }
  }

  if (f) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
