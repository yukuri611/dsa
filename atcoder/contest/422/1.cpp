#include <bits/stdc++.h>

using namespace std;

int main() {
  string S; cin >> S;
  int x = S[0] - '0'; int y = S[2] - '0';
  x--; y--;
  int total = x * 8 + y + 1;
  int res1 = total / 8 + 1; int res2 = total % 8 + 1;
  cout << res1 << "-" << res2 << endl;
  return 0;
}
