#include <bits/stdc++.h>

using namespace std;

int main() {
  string S; cin >> S;
  S += '+';
  int res = 0;
  int i = 0;
  while (i < S.size()) {
    char n = S[i];
    i++;
    char op = S[i];
    i++;
    if (op == '*') {
      bool has0 = (n == '0');
      char currOp = '*';
      while (i < S.size() && currOp == '*') {
        has0 = (has0 || (S[i] == '0'));
        i++;
        currOp = S[i];
        i++;
      }
      if (!has0) res++;
    }
    else {
      if (n != '0') res++;
    }
  }

  cout << res << endl;
  return 0;
}
