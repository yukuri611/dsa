#include <bits/stdc++.h>

using namespace std;
using LL = long long;
int mod = 1000000007;

int power(LL a, int n) {
  LL res = 1;
  while(n > 0) {
    if (n & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return res;
}

int inverse(int a) {
  return power(a, mod - 2);
}

int factorial(int n) {
  LL res = 1;
  for (int i = 2; i <= n; ++i) {
    res = (res * i) % mod;
  }
  return res;
}

int combination(int x, int y) {
  int a = factorial(x);
  int b = factorial(x-y);
  int c = factorial(y);
  return (1LL * a * inverse((1LL * b * c) % mod)) % mod;
}

int main() {
  int X, Y; cin >> X >> Y;
  if ((2 * Y - X) % 3 != 0 || (2 * X - Y) % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  int x = (2 * Y - X) / 3; int y = (2 * X - Y) / 3;
  if (x < 0 || y < 0) {
    cout << 0 << endl;
    return 0;
  }
  cout << combination(x + y, x) << endl;
  return 0;
}
