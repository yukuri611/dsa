#include <bits/stdc++.h>

using namespace std;

int main() {
  int X, Y; cin >> X >> Y;
  if (X + Y > 12) cout << (X + Y - 12) << endl;
  else  cout << X + Y << endl;
  return 0;
}
