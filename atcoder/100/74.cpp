#include <bits/stdc++.h>

using namespace std;
using LL = long long;

LL mod = 1e9 + 7;

LL factorial(LL n) {
  LL res = 1;
  for (int i = n; i > 0; --i) res = (res * i) % mod;
  return res;
}

void extGCD(LL a, LL b, LL &x, LL &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  extGCD(b, a % b, x, y);
  LL nextX = y;
  LL nextY = x - (a / b) * y;
  x = nextX;
  y = nextY;
}

LL inverse(LL n) {
  LL x, y;
  extGCD(n, mod, x, y);
  if (x < 0) x += mod;
  return x;
}
LL combination(int n, int k) {
  LL a = factorial(n);
  LL b = factorial(n - k);
  LL c = factorial(k);
  return (a * inverse((b * c % mod))) % mod;
}

LL Homogenous(int n, int k) {
  return combination(n + k - 1, k);
}

int main() {
  int n, k; cin >> n >> k;
  LL res = Homogenous(n,k) % mod;
  cout << res << endl;
  return 0;
}
