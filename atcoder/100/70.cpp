#include <bits/stdc++.h>

using namespace std;
using LL = long long;

LL mod = 1000000007;

LL power(LL m, int n) {
  LL res = 1;
  while(n > 0) {
    if (n & 1) res = (res * m) % mod;
    m = (m * m) % mod;
    n >>= 1;
  }
  return res;
}

int main() {
  LL m, n; cin >> m >> n;
  LL res = power(m, n);
  cout << res << endl;
  return 0;
}
