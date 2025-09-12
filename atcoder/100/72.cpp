#include <bits/stdc++.h>

using namespace std;
using LL = long long;
LL mod = 1000000007;

LL factorial(LL n) {
  LL res = 1;
  for (int i = 2; i <= n; ++i) res = (res * i) % mod;
  return res;
}

// LL power(LL a, LL n) {
//   LL res = 1;
//   while (n > 0) {
//     if (n & 1) res = (res * a) % mod;
//     a = (a * a) % mod;
//     n >>= 1;
//   }
//   return res;
// }

// LL inverse(int n) {
//   return power(n, mod - 2);
// }

LL extGCD(LL a, LL b, LL &x, LL &y, LL c) {
  if (b == 0) {
    x = c / a;
    y = 0;
    return a;
  }
  LL d = extGCD(b, a % b, x, y, c);
  LL nextX = y;
  LL nextY = x - ((a/b) * nextX) % mod;
  x = nextX;
  y = nextY;
  return d;
}

LL inverse(LL n) {
  LL x,y;
  extGCD(n, mod, x, y,1);
  if (x < 0) x += mod;
  return x;
}

LL combination(LL n, LL k) {
  LL a = factorial(n);
  LL b = factorial(n-k);
  LL c = factorial(k);
  return (a * inverse((b * c) % mod)) % mod;
}
int main() {
  LL W, H; cin >> W >> H;
  LL res = combination(W + H - 2, W - 1);
  cout << res << endl;
}
