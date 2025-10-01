#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 998244353;
int main() {
  ll N; cin >> N;
  ll all_pair = (((N - 1) % mod) * ((N - 2) % mod)) / 2;
  ll can_divide = 0;
  for (int b = 2; b * b <= N; ++b) {
    // 2b以上でbで割りれる数
    can_divide = (can_divide + (2 * (N / b - b) - 1)) % mod;
  }
  cout << (all_pair - can_divide + mod) % mod << endl;
  return 0;
}
