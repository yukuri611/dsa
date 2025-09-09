#include <bits/stdc++.h>
using namespace std;

using LL = long long;
LL mod = 1e9 + 7;

LL factorial(LL n) {
  LL res = 1;
  for (int i = n; i > 0; --i) {
    res = (res * i) % mod;
  }
  return res;
}

// LL power(LL a, LL n) {
//   LL res = 1;
//   while(n) {
//     if (n & 1) res = (res * a) % mod;
//     a = (a * a) % mod;
//     n >>= 1;
//   }
//   return res;
// }

// LL inverse(LL a) {
//   return power(a, mod - 2);
// }

void extGCD(LL a, LL b, LL &x, LL &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  extGCD(b, a % b, x, y);
  LL nextX = y;
  LL nextY = x - a / b * nextX;
  x = nextX;
  y = nextY;
}

LL inverse(LL a) {
  LL x;
  LL y;
  extGCD(a, mod, x, y);
  if (x < 0) x += mod;
  return x;
}

LL combination(LL n, LL k) {
  LL a = factorial(n);
  LL b = factorial(n - k);
  LL c = factorial(k);
  return (a * inverse((b * c) % mod)) % mod;
}


int main() {
  int X, Y; cin >> X >> Y;
  if ((2 * Y - X) % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }

  LL x = (2 * Y - X) / 3; LL y = Y - 2 * x;
  if (x < 0 || y < 0) {
    cout << 0 << endl;
    return 0;
  }

  cout << combination(x + y, x) << endl;
  return 0;
}
