#include <bits/stdc++.h>

using namespace std;

int main() {
  string S; cin >> S;
  string res = "";
  for (char c: S) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c ==  'u') {
      continue;
    }
    res += c;
  }
  cout << res << endl;
  return 0;
}
