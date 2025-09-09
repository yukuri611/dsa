#include <bits/stdc++.h>

using namespace std;
using LL = long long;
 
int main() {
  int n, m; cin >> n >> m;
  vector<LL> S(n-1); //S[i] = iからi+1までの距離
  for (int i = 0; i < n-1; ++i) cin >> S[i];
  vector<LL> A(m); // A[i] = i日目の移動方法
  for (int i = 0; i < m; ++i) cin >> A[i];

  vector<LL> D(n); //D[i] = 0からiまでの距離
  D[0] = 0;
  for (int i = 1; i < n; ++i) D[i] = D[i - 1] + S[i - 1];

  LL res = 0;
  LL pos = 0;
  for (int i = 0; i < m; ++i) {
    res = (res + abs(D[pos] - D[pos + A[i]])) % 100000;
    pos += A[i];
  }
  cout << res << endl;
  return 0;
}
