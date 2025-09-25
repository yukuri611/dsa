#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, Q; cin >> N >> Q;
  vector<ll> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];

  sort(A.begin(), A.end());
  
  vector<ll> sum1(N + 1,0);
  for (int i = 1; i < N + 1; ++i) {
    sum1[i] = sum1[i - 1] + A[i - 1];
  } 

  vector<ll> sum2(pow(10,6) + 1);
  for (ll b = 0; b < sum2.size(); ++b) {
    if (b > A.back()) break;
    ll id = lower_bound(A.begin(), A.end(), b) - A.begin();
    sum2[b] = sum1[id] + b * (N - id);
  }

  for (int i = 0; i < Q; ++i) {
    int B; cin >> B;
    if (B > A.back()) {
      cout << -1 << endl;
      continue;
    }
    else {
      cout << sum2[B - 1] + 1 << endl;    
    }
  }
  return 0;
}
