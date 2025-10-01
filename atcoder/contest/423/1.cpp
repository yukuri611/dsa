#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, C; cin >> X >> C;
  int y = X / (1000 + C);
  int res = 1000 * y;
  cout << res << endl;
  return 0;
}
