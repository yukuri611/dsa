#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  string S; cin >> S;
  string T;
  if (S[0] == '#') {
    T = '#';
  }
  else {
    T = 'o';
  }
  for (int i = 1; i < S.size(); ++i) {
    if (S[i] == '#') T += '#';
    else if (T[i - 1] == '#') T += 'o';
    else T += '.';
  }
  cout << T << endl;

  return 0;
}
