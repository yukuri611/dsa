#include <bits/stdc++.h>

using namespace std;
using LL = long long;
int mod = 1e9 + 7;

int extGCD(int a, int b, LL &x, LL &y, int c) {
  if (b == 0) {
    if (c % a != 0) return -1;
    x = c / a;
    y = 0; 
    return a;
  }
  int d = extGCD(b, a % b, x, y, c);

  LL nextX = y;
  LL nextY = x - (a / b * nextX) % mod;
  x = nextX; y = nextY;
  return d;
}

int inverse (int a) {
  LL x, y;
  extGCD(a, mod, x, y, 1);
  if (x < 0) x += mod;
  return x;
}

int factorial(int n) {
  LL res = 1; 
  for (int i = 2; i <= n; ++i) {
    res = (res * i) % mod;
  }
  return res;
}

int Combination(int n, int k) {
  int a = factorial(n);
  int b = factorial(n - k);
  int c = factorial(k);
  return (1LL * a * inverse((1LL * b * c) % mod)) % mod;
}

int Homogenous(int n, int k) {
  return Combination(n - 1 + k, k);
}

int main() {
  int n, k; cin >> n >> k;
  cout << Homogenous(n, k) << endl;
  return 0;
}
