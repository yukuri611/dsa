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

LL inverse(LL n, ) {


}

long long modinv(long long a, long long m) {
  //法をmとしたときのaの逆元を返す関数
	long long b = m, u = 1, v = 0;
  // a * u + b * v = a となるようにキープ
	while (b) {
		long long t = a / b;
		a -= t * b; //a = aをbで割ったあまり
    swap(a, b); // a = b, b = rになる。（ユークリッドの互除法）
		u -= t * v; 
    swap(u, v);
	}
	u %= m; 
	if (u < 0) u += m;
	return u;
}

int main() {
	// mod. 13 での逆元を求めてみる
	for (int i = 1; i < 13; ++i) {
		cout << i << " 's inv: " << modinv(i, 13) << endl;
	}
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
