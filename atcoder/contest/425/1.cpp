#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N; cin >> N;
  int res = 0;
  for (int i = 1; i <= N; ++i) {
    res += pow(-1, i) * i * i * i;
  }
  cout << res << endl;
  return 0;
}
