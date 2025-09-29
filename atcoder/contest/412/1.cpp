#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  int res = 0;
  for (int i = 0; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    res += (b > a);
  }
  cout << res << endl;
  return 0;
}
