#include <bits/stdc++.h>

using namespace std;
using LL = long long;
int mod = 1000000007;

LL factorial(int n) {
  LL res = 1;
  for (int i = 1; i <= n; ++i) {
    res = (res * i) % mod;
  }
  return res;
}

LL power(LL a, LL n) {
  LL res = 1;
  while (n > 0) {
    if (n & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return res;
}

// LL inverse(LL n){
//   //フェルマーの小定理を使用する。(nは常にmodの倍数ではない)
//   return power(n, mod - 2);
// }

LL extGCD(LL a, LL b, LL &x, LL &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  LL d = extGCD(b, a % b, x, y);
  LL nextX = y;
  LL nextY = x - a/b * y;
  x = nextX;
  y = nextY;
  return d;
}

LL inverse(LL n) {
  //拡張ユークリッドの互除法を使用
  LL x;
  LL y;
  extGCD(n, mod, x, y);
  if (x < 0) x += mod;
  return x;
}

LL combination(LL n, LL r) {
  LL a = factorial(n);
  LL b = factorial(n-r);
  LL c = factorial(r);
  return (a * inverse((b * c) % mod)) % mod;
}
int main() {
  int W, H; cin >> W >> H;
  LL n = W + H - 2;
  LL r = W - 1;
  cout << combination(n, r) << endl;
}
