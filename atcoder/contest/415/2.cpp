#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  string S; cin >> S;
  int N = S.size();
  int c = 0;
  int j = -1;
  for (int i = 0; i < N; ++i) {
    if (S[i] == '#') {
      if (c == 1) {
        cout << j + 1 << "," << i + 1 << endl;
        j = -1;
        c = 0;
      }
      else {
        c = 1;
        j = i;
      }
    }
  }
  return 0;
}
