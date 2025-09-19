#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int N, K; cin >> N >> K;
  vector<ll> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  ll cost = LLONG_MAX;
  for (int bit = 0; bit < (1 << N); bit++) {
    int count = 1;
    ll curr_cost = 0;
    vector<ll> currA = A;
    for (int i = 1; i < N; ++i) {
      if ((bit >> i) & 1) {
        //i番目の建物が見えるようにする。
        count++;
        if (currA[i-1] >= currA[i]) {
          curr_cost += currA[i-1] + 1 - currA[i];
          currA[i] = currA[i - 1] + 1;
        }
      }
      currA[i] = max(currA[i], currA[i - 1]);
    }
    if (count < K) continue;
    cost = min(cost, curr_cost);
  }

  cout << cost << endl;
  return 0;
}
