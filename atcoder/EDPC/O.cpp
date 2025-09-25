#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

int main() {
  int N; cin >> N;
  vector<vector<ll>> A(N, vector<ll>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> A[i][j];
    }
  }

  vector<ll> dp((1 << N), 0); //dp[s] = cまでの男性と集合sの女性がマッチ済みの時、最大の組み合わせ数
  dp[0] = 1;
   
  for (int s = 1; s < (1 << N); ++s){ 
    int c = __builtin_popcount(s);
    for (int j = 0; j < N; ++j) {
      if ((s >> j) & 1 == 0) continue;
      int prevS = s ^ (1 << j);
      if(A[c - 1][j]) dp[s] = (dp[s] + dp[prevS]) % mod;
    }
  }

  cout << dp[(1<<N) - 1] << endl;
  return 0;
} 
