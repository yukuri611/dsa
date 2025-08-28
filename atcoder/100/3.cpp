#include <iostream>
#include <string>

using namespace std;

int main() {
  string s; cin >> s;
  int res = 0;
  for (int i = 0; i < s.length(); ++i) {
    int j = 0;
    while(s[i + j] == 'A' || s[i + j] == 'C' || s[i + j] == 'T' || s[i + j] == 'G') {
      j++;
    }
    res = max(res, j);
  }
  cout << res << endl;
  return 0;
}
